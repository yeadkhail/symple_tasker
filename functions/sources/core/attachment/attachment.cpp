//
// Created by yead on 11/4/23.
//

#include <csignal>
#include <unistd.h>
#include "../../../../headers/attachment.h"
#include "../../../../headers/PathManager.h"
#include "../../../../headers/Task.h"

namespace core {
    using namespace std;
        string attachment::getattachmentname()
        {
            return attachmentname;
        }
        int attachment::moveattachmenttoattachmentfolder()
        {
            cout<<"Enter the full path of the attachment: ";
            string _attachment;
            cin >> _attachment;
            bool check  = copyFile(_attachment,getattachmentfolder());
            if(!check)
            {
                //cout<<"Error copying file"<<endl;
                return -1;
            }
            attachmentname = getFileName(_attachment);
            return 0;
        }
        int attachment::moveattachmenttocurrentfolder()
        {
            if(attachmentname == "NULL")
            {
                cout<<"No attachment found"<<endl;
                return 1;
            }
            char buffer[FILENAME_MAX];
            if (getcwd(buffer, sizeof(buffer)) != nullptr) {
                std::string currentDirName(buffer);
                string sourcefilename = getattachmentfolder() + '/' + attachmentname;
                bool flag = copyFile(sourcefilename, currentDirName);
                if(flag)
                {
                    cout << "Attachment copied to the current directory" << endl;
                }
                else
                {
                    cout << "Couldn't copy the file to the current directory" << endl;
                }
            }
            return 0;
        }
    int attachment::moveattachmenttocurrentfolder(string _attachmentname)
    {
        if(_attachmentname == "NULL")
        {
            cout<<"No attachment found"<<endl;
            return 1;
        }
        char buffer[FILENAME_MAX];
        if (getcwd(buffer, sizeof(buffer)) != nullptr) {
            std::string currentDirName(buffer);
            string sourcefilename = getattachmentfolder() + '/' + _attachmentname;
            bool flag = copyFile(sourcefilename, currentDirName);
            if(flag)
            {
                cout << "Attachment copied to the current directory" << endl;
            }
            else
            {
                cout << "Couldn't copy the file to the current directory" << endl;
            }
        }
        return 0;
    }
        string attachment::getFileName(const string& filePath) {
            size_t lastSeparatorPos = filePath.find_last_of("/\\");
            string fileName = filePath.substr(lastSeparatorPos + 1);
            return fileName;
        }
    bool attachment::copyFile(const string& sourceFilePath, const string& destinationFolderPath)
    {
        ifstream sourceFile(sourceFilePath, ios::binary);
        if (!sourceFile) {
            cerr << "Failed to open source file." << endl;
            return false;
        }
        string destinationFilePath = destinationFolderPath + '/'+ getFileName(sourceFilePath);
        //cout << getFileName(sourceFilePath) << endl;
        //cout<< destinationFilePath << endl;
        ofstream destinationFile(destinationFilePath, ios::binary);
        if (!destinationFile) {
            cerr << "Failed to create destination file." << std::endl;
            sourceFile.close();
            return false;
        }
        destinationFile << sourceFile.rdbuf();
        sourceFile.close();
        destinationFile.close();

        return true;
    }
    void attachment::showattachment()
    {
            cout << "Enter task name: ";
            string tasknamefrominput;
            cin.ignore();
            getline(cin, tasknamefrominput);
        string taskfile = PathManager::gettaskfile();
        ifstream workfile(taskfile);

        if (!workfile.is_open())
        {
            cerr << "Error opening the task file " << taskfile << ".\n";
            return;
        }

        string lineee;
        cout << "Task name: " << tasknamefrominput << endl;
        while (getline(workfile, lineee))
        {
            core::Task mytask(lineee);
            std::string tasknamefromfile = mytask.gettaskname();
            cout << mytask.gettaskname() << endl;
            if(tasknamefrominput == tasknamefromfile)
            {
                string _attachmentname = mytask.getattachment();

                if(_attachmentname == "NULL")
                {
                    cout<<"No attachment found"<<endl;
                    return;
                }
                attachmentname = mytask.getattachment();
                moveattachmenttocurrentfolder(_attachmentname);
                return;
            }

        }


        cout << "No task found with the name " << tasknamefrominput << endl;
        return;

    }

} // core
//
// Created by yead on 11/4/23.
//

#include <csignal>
#include <unistd.h>
#include "../../../../headers/attachment.h"

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
                //cout<<"No attachment to move"<<endl;
                return 1;
            }
            char buffer[FILENAME_MAX];
            if (getcwd(buffer, sizeof(buffer)) != nullptr) {
                std::string currentDirName(buffer);
                string sourcefilename = getattachmentfolder() + attachmentname;
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
        string destinationFilePath = destinationFolderPath + getFileName(sourceFilePath);
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

} // core
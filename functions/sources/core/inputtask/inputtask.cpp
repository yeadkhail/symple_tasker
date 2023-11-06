//
// Created by yead on 9/16/23.
//

#include "../../../../headers/inputtask.h"
#include "../../../../headers/PathManager.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
namespace core {
    int inputtask::insert(void)
    {
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open())
        {
            cout << "Error while opening file" << endl;
            exit(1);
        }
        int numLines = 0;
        std::string unused;
        while (std::getline(read, unused))
            ++numLines;
        read.close();
        insertaskdata();
        string dot = "^";
        string insert = to_string(numLines) + dot + packtask();
        ofstream app(filename, ios::app);
        if (!app.is_open())
        {
            cout << "Error appending to the file: " << filename << endl;
            return 0;
        }

        app << insert << endl;
        app.close();

        return 0;
    }

    void inputtask::insertaskdata()
    {
        cout<<"Enter task name: ";
        getline(cin,taskname);
        cout<<"Enter task detail: ";
        getline(cin,taskdetail);
        cout<<"Enter task tag: ";
        getline(cin,tasktag);
        cout<<"Enter task date: ";
        getline(cin,date);
        cout<<"Do you want to attach an attachment?(y/n): ";
        char attach;
        cin >> attach;
        if(attach == 'y')
        {
//            cout<<"Enter the full path of the attachment: ";
//            string attachment;
//            cin >> attachment;
//            copyFile(attachment,attachmentfolderpathstring());
//            string destinationFilePath = attachmentfolderpathstring() + getFileName(attachment);
//            //cout << "hello" << endl;
//            taskdata.attachment = destinationFilePath;
//            //cout<< taskdata.attachment;
        }
        else
            attachment = "NULL";
    }
} // core

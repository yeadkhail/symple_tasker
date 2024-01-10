//
// Created by yead on 11/4/23.
//

#ifndef SYMPLE_TASKER_ATTACHMENT_H
#define SYMPLE_TASKER_ATTACHMENT_H
#include "PathManager.h"
#include<iostream>
#include <fstream>
namespace core {

    class attachment : virtual public PathManager  // inherit from Task
    {
    private:
        string attachmentname;
    public:
        attachment():PathManager()
        {
            attachmentname = "NULL";
        }
        attachment(string _attachmentname):PathManager()
        {
            attachmentname = _attachmentname;
        }
        string getattachmentname();
        int moveattachmenttoattachmentfolder();
        int moveattachmenttocurrentfolder();
        string getFileName(const string& filePath);
        bool copyFile(const string& sourceFilePath, const string& destinationFolderPath);
    };

} // core

#endif //SYMPLE_TASKER_ATTACHMENT_H

//
// Created by yead on 9/15/23.
//

#include "../../../../headers/PathManager.h"

namespace core {
    PathManager::PathManager()
    {
        home = getenv("HOME");
        std::string Sym = "/.sym";
        symfolder = home + Sym;
        taskfile = symfolder + "/tasks";
        tagfile = symfolder + "/tags";
        encryptedtaskfile = taskfile + ".enc";
        profilefile = symfolder + "/profile";
        notesfolder = symfolder + "/notes";
        attachmentfolder = symfolder + "/attachments";
    }
    string PathManager::gethome()
    {
        return home;
    }
    string PathManager::getsymfolder()
    {
        return symfolder;
    }
    string PathManager::gettaskfile()
    {
        return taskfile;
    }
    string PathManager::gettagfile()
    {
        return tagfile;
    }
    string PathManager::getencryptedtaskfile()
    {
        return encryptedtaskfile;
    }
    string PathManager::getprofilefile()
    {
        return profilefile;
    }
    string PathManager::getnotesfolder()
    {
        return notesfolder;
    }
    string PathManager::getattachmentfolder()
    {
        return attachmentfolder;
    }

} // core
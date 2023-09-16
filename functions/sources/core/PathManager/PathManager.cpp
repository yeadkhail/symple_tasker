//
// Created by yead on 9/15/23.
//

#include "../../../../headers/PathManager.h"

namespace core {
    PathManager::PathManager()
    {
        home = std::getenv("HOME");
        std::string Sym = "/.sym";
        symfolder = home + Sym;
        taskfile = symfolder + "/taskfile";
    }
    std::string PathManager::gethome()
    {
        return home;
    }
    std::string PathManager::getsymfolder()
    {
        return symfolder;
    }
    std::string PathManager::gettaskfile()
    {
        return taskfile;
    }
} // core
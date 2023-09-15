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
    }
    std::string PathManager::gethome()
    {
        return home;
    }
    std::string PathManager::getsymfolder()
    {
        return symfolder;
    }
} // core
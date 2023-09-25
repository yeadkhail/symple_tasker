//
// Created by yead on 9/15/23.
//

#ifndef SYMPLE_TASKER_PATHMANAGER_H
#define SYMPLE_TASKER_PATHMANAGER_H
#include<string>
namespace core {

    class PathManager {
    private:
        std::string home;
        std::string symfolder;
        std::string taskfile;
    protected:
        PathManager();
        //PathManager();
        std::string gethome();
        std::string getsymfolder();
        std::string gettaskfile();

    };

} // core

#endif //SYMPLE_TASKER_PATHMANAGER_H

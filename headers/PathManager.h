//
// Created by yead on 9/15/23.
//

#ifndef SYMPLE_TASKER_PATHMANAGER_H
#define SYMPLE_TASKER_PATHMANAGER_H
#include<string>
using namespace std;
namespace core {

    class PathManager {
    private:
        string home;
        string symfolder;
        string taskfile;
        string tagfile;
    public:
        PathManager();
        //PathManager();
        string gethome();
        string getsymfolder();
        string gettaskfile();
        string gettagfile();
    };

} // core

#endif //SYMPLE_TASKER_PATHMANAGER_H

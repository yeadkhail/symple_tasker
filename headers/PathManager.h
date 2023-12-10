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
        string encryptedtaskfile;
        string profilefile;
        string notesfolder;
    public:
        PathManager();
        //PathManager();
        string gethome();
        string getsymfolder();
        string gettaskfile();
        string getencryptedtaskfile();
        string gettagfile();
        string getprofilefile();
        string getnotesfolder();
    };

} // core

#endif //SYMPLE_TASKER_PATHMANAGER_H

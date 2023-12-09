//
// Created by yead on 9/25/23.
//

#ifndef SYMPLE_TASKER_INITIALIZER_H
#define SYMPLE_TASKER_INITIALIZER_H
#include "PathManager.h"
#include<fstream>
namespace core {

    class initializer: public PathManager
    {
    private:
        string name;
        string phone;
        string email;
        string address;
        class filenotcreated{};
        class couldntencrypterrr{};
    public:
        bool dotsymfolderchecker();
        void createdirstructure();
        void createdotsymfolder();
        void createprofilefile();
        void createattachmentfolder();
        void createtaskfile();
        void createtagfile();
        void createnotesfolder();
        void encrypttaskfile();

    };

} // core

#endif //SYMPLE_TASKER_INITIALIZER_H

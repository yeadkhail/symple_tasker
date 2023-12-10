//
// Created by yead on 11/6/23.
//

#ifndef SYMPLE_TASKER_TAGHANDLER_H
#define SYMPLE_TASKER_TAGHANDLER_H

#include "PathManager.h"
#include <iostream>
#include <cstring>
#include <fstream>
namespace core {

    class taghandler : public PathManager{
    private:
        string tagname;
        int importance;
    public:
        taghandler(string _tagname,int _importance);
        taghandler();
        taghandler(string line);
        string gettagname();
        int getimportance();
        void inserttag();
        bool isTagExist(string tagname);
        static bool isimportant(string tagname);
        bool isimportant();
    };

} // core

#endif //SYMPLE_TASKER_TAGHANDLER_H

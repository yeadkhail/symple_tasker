//
// Created by yead on 1/11/24.
//

#ifndef SYMPLE_TASKER_INPUTHANDLER_H
#define SYMPLE_TASKER_INPUTHANDLER_H
#include "PathManager.h"
#include "Task.h"
#include<cstdio>

namespace core {

    class inputhandler :virtual public PathManager,virtual public Task
    {
    private:
        string filename;
    public:
        inputhandler();
        void deleteTask();
        void editTask();
    };

} // core

#endif //SYMPLE_TASKER_INPUTHANDLER_H

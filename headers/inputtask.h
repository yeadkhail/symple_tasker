//
// Created by yead on 9/16/23.
//

#ifndef SYMPLE_TASKER_INPUTTASK_H
#define SYMPLE_TASKER_INPUTTASK_H
#include"Task.h"
#include "PathManager.h"

namespace core {

class inputtask : public Task,public PathManager  // inherit from Task
    {
    protected:

    public:
        inputtask():Task(),PathManager(){};
        int insert(void);
        void insertaskdata();
    };

} // core

#endif //SYMPLE_TASKER_INPUTTASK_H

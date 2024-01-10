//
// Created by yead on 9/16/23.
//

#ifndef SYMPLE_TASKER_TASKTRAVERSER_H
#define SYMPLE_TASKER_TASKTRAVERSER_H
#include "Task.h"
#include "taghandler.h"
#include "PathManager.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
namespace core {
    using namespace std;
    class tasktraverser : virtual public Task, virtual public taghandler,virtual public PathManager  // inherit from Task, taghandler,pathmanager
    {
    protected:
        std::vector<string> _taskID;
        std::vector<string> _taskName;
        std::vector <string> _taskDetail;
        std::vector <string> _taskTag;
        std::vector <string> _taskDate;
        std::vector <string> _taskAttachment;
        int taskNumber;
    public:
        tasktraverser(){}
        std::string gettaskName();
        std::string gettaskDetail();
        std::string gettaskTag();
        std::string gettaskDate();
        std::string getAttachment();
        void findTask(int taskNum);
        void findExpired();
        void findUrgent();
        void findImportant();
        void findNotUrgent();
        void findNotImportant();
        void UrgentImportant();
        void notUrgentImportant();
        void notUrgentnotImportant();
        void urgentNotImportant();
//        ~tasktraverser();
    };

} // core

#endif //SYMPLE_TASKER_TASKTRAVERSER_H

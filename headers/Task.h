//
// Created by yead on 9/15/23.
//

#ifndef SYMPLE_TASKER_TASK_H
#define SYMPLE_TASKER_TASK_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <chrono>
#include "base64.h"
using namespace std;
namespace core
{

    class Task
    {
    private:
        std::string taskname;
        std::string taskdetail;
        std::string tasktag;
        std::string date;
        std::string attachment;
    public:
        Task();
        Task(std::string line);
        std::string gettaskname();
        std::string gettaskdetail();
        std::string gettasktag();
        std::string getattachment();
        int getdatedate();
        int getdatemonth();
        int getdateyear();
        bool isUrgent();

    };
} // core

#endif // SYMPLE_TASKER_TASK_H

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
        int showdatedate(const std::string& date);
        int showdatemonth(const std::string& date);
        int showdateyear(const std::string& date);
        bool isUrgent(const Task &taskdata);
    };
} // core

#endif // SYMPLE_TASKER_TASK_H

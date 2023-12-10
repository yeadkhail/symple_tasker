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
#include <sstream>
#include "base64.h"
using namespace std;
namespace core
{

    class Task
    {
    protected:
        std::string taskname;
        std::string taskdetail;
        std::string tasktag;
        std::string date;
        std::string attachment;
    public:
        Task(){}
        Task(std::string line);
        Task(string _taskname,string _taskdetail,string _tasktag, string _date,string _attachment);
        std::string gettaskname() const;
        std::string gettaskdetail()const;
        std::string gettasktag();
        std::string getattachment();
        string packtask();
        int getdatedate();
        int getdatemonth();
        int getdateyear();
        bool isUrgent();

        void settaskname(string name);
        void settaskdetail(string detail);
        void settasktag(string tag);
        void setattachment(string att);
        bool dateinputchecker(const string dateStr);
        bool isExpired();
        ~Task() {}
    };
} // core

#endif // SYMPLE_TASKER_TASK_H

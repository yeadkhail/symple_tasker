//
// Created by yead on 9/15/23.
//

#include "../../../../headers/Task.h"

namespace core
{
    std::string Task::gettaskname()
    {
        return taskname;
    }
    std::string Task::gettaskdetail()
    {
        return taskdetail;
    }
    std::string Task::gettasktag()
    {
        return tasktag;
    }
    std::string Task::getattachment()
    {
        return attachment;
    }
    int Task::getdatedate()
    {
        istringstream issdate(date);
        string part;
        getline(issdate, part, '/');
        int intdate = stoi(part);
        return intdate;
    }
    int Task::getdatemonth()
    {
        istringstream issdate(date);
        string part;
        getline(issdate, part, '/');
        getline(issdate, part, '/');
        int intmonth = stoi(part);
        return intmonth;
    }
    int Task::getdateyear()
    {
        istringstream issdate(date);
        string part;
        getline(issdate, part, '/');
        getline(issdate, part, '/');
        getline(issdate, part, '/');
        int intyear = stoi(part);
        return intyear;
    }
    bool Task::isUrgent()
    {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

        // Convert the system time to a time_t object
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        // Convert the time_t object to a struct tm
        std::tm *timeInfo = std::localtime(&currentTime);

        // Extract the date, month, and year
        int day = timeInfo->tm_mday;
        int month = timeInfo->tm_mon + 1;    // tm_mon is zero-based
        int year = timeInfo->tm_year + 1900; // tm_year is years since 1900
        if (Task::getdateyear() < year)
        {
            return false;
        }
        else if (Task::getdateyear() == year)
        {
            if (Task::getdatemonth() < month)
            {
                return false;
            }
            else if (Task::getdatemonth() == month)
            {
                if (Task::getdatedate() < day)
                {
                    return false;
                }
                else if (Task::getdatedate() == day)
                {
                    return true;
                }
                else if (Task::getdatedate() <= day + 1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (Task::getdatemonth() == month + 1)
            {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                {
                    if (Task::getdatedate() == 1 && day == 31)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (month == 4 || month == 6 || month == 9 || month == 11)
                {
                    if (Task::getdatedate() == 1 && day == 30)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (month == 2 && year % 4 == 0)
                {
                    if (Task::getdatedate() == 1 && day == 29)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (month == 2 && year % 4 != 0)
                {
                    if (Task::getdatedate() == 1 && day == 28)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if (Task::getdateyear() == year + 1 && month == 12 && day == 31)
        {
            if (Task::getdatemonth() == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    Task::Task(std::string line)
    {
        //code
    }
} // core
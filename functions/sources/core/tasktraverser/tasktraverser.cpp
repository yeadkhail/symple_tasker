//
// Created by yead on 9/16/23.
//

#include "../../../../headers/tasktraverser.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace core {
    using namespace std;
    void tasktraverser::findTask(int taskNum){ ///Done
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open())
        {
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }
        string taskString;

        while (getline(read, taskString)) {
            Task decoded(taskString);
            string currentNum;
            istringstream iss(taskString);
            getline(iss, currentNum, '^');
                taskNumber = stoi(currentNum);
                if (taskNumber == taskNum) {
                    cout << "Task ID: " << decoded.gettaskid() << endl;
                    cout << "Task name: " << decoded.gettaskname() << endl;
                    cout << "Task details: " << decoded.gettaskdetail() << endl;
                    cout << "Task tag: " << decoded.gettasktag()  << endl;
                    cout << "Date: " << decoded.gettaskdate() << endl;
                    cout << "Attachment: " << decoded.getattachment() << endl;
                    return;
            }
        }
    }
    void tasktraverser::findExpired(){ ///Done
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }

        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (decoded.isExpired()) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
    void tasktraverser::findUrgent(){ ///Done
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }

        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (decoded.isUrgent()) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
    void tasktraverser::findImportant(){
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }
        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (taghandler::isimportant(decoded.gettasktag())) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
    void tasktraverser::findNotUrgent(){ ///Done
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }
        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (!decoded.isUrgent()) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
    void tasktraverser::findNotImportant(){
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }
        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (!taghandler::isimportant(decoded.gettasktag())) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
    void tasktraverser::UrgentImportant(){
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }
        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (decoded.isUrgent() && taghandler::isimportant(decoded.gettasktag())) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
    void tasktraverser::notUrgentImportant(){
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }
        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (!decoded.isUrgent() && taghandler::isimportant(decoded.gettasktag())) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
    void tasktraverser::notUrgentnotImportant(){
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }
        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (!decoded.isExpired() && !decoded.isUrgent() && !taghandler::isimportant(decoded.gettasktag())) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
    void tasktraverser::urgentNotImportant(){
        string filename = gettaskfile();
        ifstream read(filename);
        if (!read.is_open()){
            cout << "Error while opening file" << endl;
            exit(1);
        }
        // Discard the first line
        string discardLine;
        for (int i = 0; i < 1; ++i) {
            getline(read, discardLine);
        }
        string taskString;
        while (getline(read, taskString)) {
            Task decoded(taskString);
            if (decoded.isUrgent() && !taghandler::isimportant(decoded.gettasktag())) {
                _taskID.push_back(decoded.gettaskid());
                _taskName.push_back(decoded.gettaskname());
                _taskDetail.push_back(decoded.gettaskdetail());
                _taskTag.push_back(decoded.gettasktag());
                _taskDate.push_back(decoded.gettaskdate());
                _taskAttachment.push_back(decoded.getattachment());
            } else {
                continue;
            }
        }
    }
} // core

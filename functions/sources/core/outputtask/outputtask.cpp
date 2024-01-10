//
// created by zawad on 18/12/2023
//

#include "../../../../headers/outputtask.h"

using namespace std;
namespace core{
    void outputtask::showUrgent() { ///Done
        tasktraverser::findUrgent();
        for (int i = 0; i < _taskName.size(); ++i) {
            cout << "Task Name: " << _taskName[i] << endl;
            cout << "Task Detail: " << _taskDetail[i] << endl;
            cout << "Task Tag: " << _taskTag[i] << endl;
            cout << "Task Date: " << _taskDate[i] << endl;
            cout << "Task Attachment: " << _taskAttachment[i] << endl;
            cout << "--------------------------" << endl;
        }
    }
    void outputtask::showImportant() { ///Done
        tasktraverser::findImportant();
        for (int i = 0; i < _taskName.size(); ++i) {
            cout << "Task Name: " << _taskName[i] << endl;
            cout << "Task Detail: " << _taskDetail[i] << endl;
            cout << "Task Tag: " << _taskTag[i] << endl;
            cout << "Task Date: " << _taskDate[i] << endl;
            cout << "Task Attachment: " << _taskAttachment[i] << endl;
            cout << "--------------------------" << endl;
        }
    }
    void outputtask::shownotUrgent() { ///Done
        tasktraverser::findNotUrgent();
        for (int i = 0; i < _taskName.size(); ++i) {
            cout << "Task Name: " << _taskName[i] << endl;
            cout << "Task Detail: " << _taskDetail[i] << endl;
            cout << "Task Tag: " << _taskTag[i] << endl;
            cout << "Task Date: " << _taskDate[i] << endl;
            cout << "Task Attachment: " << _taskAttachment[i] << endl;
            cout << "--------------------------" << endl;
        }
    }
    void outputtask::shownotImportant() { ///Done
        tasktraverser::findNotImportant();
        for (int i = 0; i < _taskName.size(); ++i) {
            cout << "Task Name: " << _taskName[i] << endl;
            cout << "Task Detail: " << _taskDetail[i] << endl;
            cout << "Task Tag: " << _taskTag[i] << endl;
            cout << "Task Date: " << _taskDate[i] << endl;
            cout << "Task Attachment: " << _taskAttachment[i] << endl;
            cout << "--------------------------" << endl;
        }
    }
    void outputtask::showUrgentImportant() {
        tasktraverser::UrgentImportant();
        for (int i = 0; i < _taskName.size(); ++i) {
            cout << "Task Name: " << _taskName[i] << endl;
            cout << "Task Detail: " << _taskDetail[i] << endl;
            cout << "Task Tag: " << _taskTag[i] << endl;
            cout << "Task Date: " << _taskDate[i] << endl;
            cout << "Task Attachment: " << _taskAttachment[i] << endl;
            cout << "--------------------------" << endl;
        }
    }
    void outputtask::showUrgentnotImportant() {
        tasktraverser::urgentNotImportant();
        for (int i = 0; i < _taskName.size(); ++i) {
            cout << "Task Name: " << _taskName[i] << endl;
            cout << "Task Detail: " << _taskDetail[i] << endl;
            cout << "Task Tag: " << _taskTag[i] << endl;
            cout << "Task Date: " << _taskDate[i] << endl;
            cout << "Task Attachment: " << _taskAttachment[i] << endl;
            cout << "--------------------------" << endl;
        }
    }
    void outputtask::shownotUrgentImportant() {
        tasktraverser::notUrgentImportant();
        for (int i = 0; i < _taskName.size(); ++i) {
            cout << "Task Name: " << _taskName[i] << endl;
            cout << "Task Detail: " << _taskDetail[i] << endl;
            cout << "Task Tag: " << _taskTag[i] << endl;
            cout << "Task Date: " << _taskDate[i] << endl;
            cout << "Task Attachment: " << _taskAttachment[i] << endl;
            cout << "--------------------------" << endl;
        }
    }
    void outputtask::shownotUrgentnotImportant() {
        tasktraverser::notUrgentnotImportant();
        for (int i = 0; i < _taskName.size(); ++i) {
            cout << "Task Name: " << _taskName[i] << endl;
            cout << "Task Detail: " << _taskDetail[i] << endl;
            cout << "Task Tag: " << _taskTag[i] << endl;
            cout << "Task Date: " << _taskDate[i] << endl;
            cout << "Task Attachment: " << _taskAttachment[i] << endl;
            cout << "--------------------------" << endl;
        }
    }
} //core
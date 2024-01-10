//
// created by zawad on 18/12/2023
//

#ifndef SYMPLE_TASKER_OUTPUTTASK_H
#define SYMPLE_TASKER_OUTPUTTASK_H
#include "tasktraverser.h"

namespace core  {
    class outputtask: public tasktraverser{
        protected:
        public:
        outputtask() {}
        void printHistory();
        void showExpired();
        void showUrgent();
        void showImportant();
        void shownotUrgent();
        void shownotImportant();
        void showUrgentImportant();
        void showUrgentnotImportant();
        void shownotUrgentImportant();
        void shownotUrgentnotImportant();
//        ~outputtask() {}
    };
}//core

#endif //SYMPLE_TASKER_OUTPUTTASK_H

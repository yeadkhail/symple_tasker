//
// Created by yead on 9/18/23.
//

#ifndef SYMPLE_TASKER_TABLE_H
#define SYMPLE_TASKER_TABLE_H
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
#include "Task.h"
#include "PathManager.h"
#include <iomanip>
using namespace  std;
namespace core {
    //using namespace std;
   class table {
        public:
        void modifyFilesForTable();
        void FilesForTable();
        void fileChangerForOutputTable();
        void finalFileChangerForOutputTable();
        void outputTable();
        void showTable();
        void deleteFiles();
    };

} // core

#endif //SYMPLE_TASKER_TABLE_H

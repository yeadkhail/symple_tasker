//
// Created by yead on 9/16/23.
//

#ifndef SYMPLE_TASKER_VISUALS_H
#define SYMPLE_TASKER_VISUALS_H
#include <iostream>
#include <fstream>
#include "PathManager.h"
namespace core {

    class Visuals{
    private:
    public:
        static void title();
        static void motivation();
        static void showintro();
        static void showhelp();
        static void showversion();
        static  void randomiser();
        static void showporfile();
    };

} // core

#endif //SYMPLE_TASKER_VISUALS_H

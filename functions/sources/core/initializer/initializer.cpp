//
// Created by yead on 9/25/23.
//

#include "../../../../headers/initializer.h"

namespace core {
     bool initializer::dotsymfolderchecker()
     {
         ifstream checker;
         checker.open(getsymfolder());
         if(!checker)
         {
             return false;
         }
         else
         {
             return true;
         }
     }
} // core
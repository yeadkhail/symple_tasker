#include <iostream>
#include"headers/PathManager.h"
using namespace std;
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::cout<< "MY PROJECT";
    core::PathManager mypath;
    cout<< mypath.gethome()<< endl;
    cout << mypath.getsymfolder() << endl;
    return 0;
}

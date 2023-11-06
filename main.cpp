#include <iostream>
#include"headers/PathManager.h"
#include "headers/Task.h"
#include "headers/Visuals.h"
#include "headers/base64.h"
#include "headers/inputtask.h"
using namespace std;
int main() {




















    //==========================================test=here=====comment=after=testing==========================================

    //std::cout << "Hello, World!" << std::endl;
//    std::cout<< "MY PROJECT";
//    core::PathManager mypath;
//    cout<< mypath.gethome()<< endl;
//    cout << mypath.getsymfolder() << endl;
//    core::Task mytask("1^presentation^make the presentation slides^project^23/05/2023^NULL");
//    cout<< mytask.gettaskname()<<endl;
//    cout<< mytask.gettaskdetail()<<endl;
//    cout<< mytask.gettasktag()<<endl;
//    cout<< mytask.getattachment()<<endl;
//    cout<< mytask.getdatedate()<<endl;
//    cout<< mytask.getdatemonth()<<endl;
//    cout<< mytask.getdateyear()<<endl;
//    cout<< mytask.isUrgent()<<endl;
//    core::Visuals::title();
//    core::Visuals::motivation();
//      core::Visuals::showintro();
//      core::Visuals::showhelp();
//      std::string s = crypto::base64::encode("1^presentation^make the \npresentation slides^project^23/05/2023^NULL");
//      cout << s << endl;
//      cout << crypto::base64::encode(mytask.gettaskname()) << endl;
//      cout << crypto::base64::decode(s) << endl;
    core::Task mytask("presentation","make the presentation slides","project","23/05/2023","NULL");
    cout <<"Task: "<< mytask.gettaskname() << endl;
    cout << mytask.packtask() << endl;
    std::string testData = "Hello";
    std::string encodedData = crypto::base64::encode(testData);
    std::string decodedData = crypto::base64::decode(encodedData);
    cout << "Original: " << testData << endl;
    cout << "Encoded: " << encodedData << endl;
    cout << "Decoded: " << decodedData << endl;
    core::inputtask myinputtask;
    myinputtask.insert();
    return 0;
}

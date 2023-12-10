#include <iostream>
#include"headers/PathManager.h"
#include "headers/Task.h"
#include "headers/Visuals.h"
#include "headers/base64.h"
#include "headers/inputtask.h"
#include "headers/taghandler.h"
#include "headers/table.h"
#include "headers/aes128.h"
#include "headers/initializer.h"
using namespace std;


int main(int argc, char *argv[])
{

    //=================================================main body of code starts here == you may comment them while testing=====================================

    core::initializer maininitializer;

    if(argc == 1) {
        begin:
        core::Visuals::title();
        if(!maininitializer.dotsymfolderchecker())
        {
            maininitializer.initialize();
            goto begin;
        }
        else
        {
            //core::table::showTable();
            start:
            string input;
            cout << "Enter your command >> ";
            cin >> input;
//            if(input == "insert") core::inputtask::insert();
//            else if(input == "edit-task") core::inputtask::TaskEdit();
//            else if(input == "delete-task") core::inputtask::TaskDelete();
            //else if(input == "update") updateTask();
            //else if(input == "show") showTask();
            if(input == "help") core::Visuals::showhelp();
//            else if(input == "version") core::Visuals::version();
//            else if(input == "randomizer") core::Visuals::randomizer();
//            else if(input == "edit-tag") core::taghandler::TagEdit();
//            else if(input =="delete-tag") core::taghandler::TagDelete();
//            else if(input == "insert-tag") core::taghandler::TagInsert();
//            else if(input == "search-tagwise") core::taghandler::TagWise();
//            else if(input == "show-attachment") core::Visuals::findAttachment();
//            else if(input == "show-expired") core::Visuals::showExpired();
//            else if(input == "history") core::Visuals::history();
//            else if(input == "show-table") core::Visuals::showTable();
            else if(input == "clear") system("clear");  //system("cls");
            else if(input == "exit")
            {
                system("sleep 1");
                cout << "Encrypting your data" << endl;
                system("sleep 1");
                maininitializer.encrypttaskfile();
                cout << "Exiting the program" << endl;
                system("clear");
                exit(0);
            }
            else cout << "Invalid command" << endl;
            if(input != "exit" )
            {
                goto start;
            }
        }

    }






















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
//      std::string s = crypto::base64::encode("1^presentation^make the \npresentation slides^project^23/05/2023^NULL");
//      cout << s << endl;
//      cout << crypto::base64::encode(mytask.gettaskname()) << endl;
//      cout << crypto::base64::decode(s) << endl;
//    core::Task mytask("presentation","make the presentation slides","project","23/05/2023","NULL");
//    cout <<"Task: "<< mytask.gettaskname() << endl;
//    cout << mytask.packtask() << endl;
//    std::string testData = "Hello";
//    std::string encodedData = crypto::base64::encode(testData);
//    std::string decodedData = crypto::base64::decode(encodedData);
//    cout << "Original: " << testData << endl;
//    cout << "Encoded: " << encodedData << endl;
//    cout << "Decoded: " << decodedData << endl;
    //core::inputtask myinputtask;
    //myinputtask.insert();
//    core::Visuals::asciiArtedName();
//      core::taghandler mytaghandler("1^project");
//      cout << mytaghandler.gettagname() << endl;
//        cout << mytaghandler.getimportance() << endl;
//    core::taghandler mytaghandler2("1^project");
//    mytaghandler2.inserttag();
//    core::table mytable;
//    mytable.showTable();
//    core::PathManager p;
//    crypto::aes128 myaes;
//    //myaes.encryptfile(p.gettaskfile(),p.getencryptedtaskfile(),"1234567890123456");
//    myaes.decryptfile(p.getencryptedtaskfile(),p.gettaskfile(),"1234567890123456");
    return 0;
}

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
#include "headers/outputtask.h"

using namespace std;


int main(int argc, char *argv[]) {

    //=================================================main body of code starts here == you may comment them while testing=====================================
    verybegin:
    try {
        core::initializer maininitializer;
        if (argc == 1) {
            begin:
            core::Visuals::showintro();
            if (!maininitializer.dotsymfolderchecker()) {
                maininitializer.initialize();
                goto begin;
            } else {
                //core::table::showTable();

                maininitializer.enterpassword();
                maininitializer.decrypttaskfile();
                core::table mytable1;
                //mytable1.showTable();
                start:
                //cin.ignore();
                string input;
                cin.ignore();
                cout << "Enter your command >> ";
                cin >> input;
            if(input == "insert"){core::inputtask myinput; myinput.insert();}
            else if(input == "insert-tag"){core::taghandler mytaghandler; mytaghandler.inputtag();}
            else if(input== "showurgent"){core::outputtask myoutput; myoutput.showUrgent();}
            else if(input == "showimportant"){core::outputtask myoutput; myoutput.showImportant();}
            else if(input == "shownoturgent"){core::outputtask myoutput; myoutput.shownotUrgent();}
            else if(input == "shownotimportant"){core::outputtask myoutput; myoutput.shownotImportant();}
            else if(input == "showurgentimportant"){core::outputtask myoutput; myoutput.showUrgentImportant();}
            else if(input == "showurgentnotimportant"){core::outputtask myoutput; myoutput.showUrgentnotImportant();}
            else if(input == "shownoturgentimportant"){core::outputtask myoutput; myoutput.shownotUrgentImportant();}
            else if(input == "shownoturgentnotimportant"){core::outputtask myoutput; myoutput.shownotUrgentnotImportant();}
//          else if(input == "edit-task") core::inputtask::TaskEdit();
//          else if(input == "delete-task") core::inputtask::TaskDelete();
//          else if(input == "update") updateTask();
//          else if(input == "show") showTask();
            else if (input == "help") core::Visuals::showhelp();
            else if(input == "version") core::Visuals::showversion();
//            else if(input == "randomizer") core::Visuals::randomizer();
//            else if(input == "edit-tag") core::taghandler::TagEdit();
//            else if(input =="delete-tag") core::taghandler::TagDelete();
//            else if(input == "insert-tag") core::taghandler::TagInsert();
//            else if(input == "search-tagwise") core::taghandler::TagWise();
//            else if(input == "show-attachment") core::Visuals::findAttachment();
//            else if(input == "show-expired") core::Visuals::showExpired();
//            else if(input == "history") core::Visuals::history();
//            else if (input == "show-table") {core::table mytable;mytable.showTable();}
                else if (input == "clear") system("clear");  //system("cls");
                else if (input == "exit") {maininitializer.exithandler();}
                else cout << "Invalid command" << endl;
                if (input != "exit") {
                    goto start;
                }
            }
        }
        else if(argc == 2)
        {
            string input = argv[1];
            if(input == "--help") core::Visuals::showhelp();
            else if(input == "--version") core::Visuals::showversion();
//            else if(input == "--randomizer") core::Visuals::randomizer();
            else if(input == "--clear") system("clear");
            else if(input == "--cleanup") { core::initializer maininitializer; maininitializer.cleanup();}
            else cout << "Invalid command" << endl;
        }

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    catch(core::initializer::filenotcreated &e)
    {
        std::cerr << "Error: File not created" << '\n';
    }
    catch(core::initializer::couldntencrypterrr &e)
    {
        std::cerr << "Error: Could not encrypt the file" << '\n';
    }
    catch(core::initializer::couldntdecrypterrr &e)
    {
        std::cout << "Error: Could not decrypt the file" << '\n';
        std::cout << "Do you want to try again?(y/n): ";
        char choice;
        std::cin >> choice;
        if(choice == 'y')
        {
            goto verybegin;
        }
        else
        {
            std::cout << "Exiting the program" << std::endl;
            exit(0);
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
//   string password = "12345";
//    cin >> password;
//    myaes.encryptfile(p.gettaskfile(),p.getencryptedtaskfile(),password);
//    //cin >> password;
//    remove(p.gettaskfile().c_str());
//    //myaes.decryptfile(p.getencryptedtaskfile(),p.gettaskfile(),password);
//    core::initializer myinitializer;
//    myinitializer.enterpassword();
//    myinitializer.decrypttaskfile();
//    core::initializer maininitializer;
//    if (!maininitializer.dotsymfolderchecker()) {
//                maininitializer.initialize();
//            }
//    maininitializer.enterpassword();
//    maininitializer.decrypttaskfile();
//    core::initializer myinitializer;
//    myinitializer.enterpassword();
//    myinitializer.decrypttaskfile();
    return 0;
}

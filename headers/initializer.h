//
// Created by yead on 9/25/23.
//

#ifndef SYMPLE_TASKER_INITIALIZER_H
#define SYMPLE_TASKER_INITIALIZER_H
#include "PathManager.h"
#include<fstream>
#include <termios.h>
#include <unistd.h>
#include "../functions/sources/crypto/aes128/aes128.cpp"
namespace core {

    class initializer: public PathManager
    {
    private:
        string name;
        string phone;
        string email;
        string address;
        string password;
        class filenotcreated{};
        class couldntencrypterrr{};
    public:
        void setname(string _name);
        void setphone(string _phone);
        void setemail(string _email);
        void setaddress(string _address);
        void setpassword(string _password);
        string getname();
        string getphone();
        string getemail();
        string getaddress();
        string getpassword();
        bool dotsymfolderchecker();
        void createdirstructure();
        void createdotsymfolder();
        void createprofilefile();
        void createattachmentfolder();
        void createtaskfile();
        void createtagfile();
        void createnotesfolder();
        void encrypttaskfile();
        void decrypttaskfile();
        bool isencrypted();
        bool isproperlydecrypted();
        bool isNumber(const std::string& str);
        void initialize();
        void setprofilevalues();
        void initializetagfile();

    };

} // core

#endif //SYMPLE_TASKER_INITIALIZER_H

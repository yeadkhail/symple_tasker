//
// Created by yead on 9/25/23.
//

#include "../../../../headers/initializer.h"

namespace core {
      void initializer::setname(string name)
      {
          this->name = name;
      }
        void initializer::setphone(string phone)
        {
            this->phone = phone;
        }
        void initializer::setemail(string email)
        {
            this->email = email;
        }
        void initializer::setaddress(string address)
        {
            this->address = address;
        }
        void initializer::setpassword(string password)
        {
            this->password = password;
        }
        string initializer::getname()
        {
            return name;
        }
        string initializer::getphone()
        {
            return phone;
        }
        string initializer::getemail()
        {
            return email;
        }
        string initializer::getaddress()
        {
            return address;
        }
        string initializer::getpassword()
        {
            return password;
        }

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
        void initializer::createdirstructure()
        {
            createdotsymfolder();
            createprofilefile();
            createattachmentfolder();
            createtaskfile();
            createtagfile();
            createnotesfolder();
            //encrypttaskfile();
        }
        void initializer::createdotsymfolder()
        {
            string command = "mkdir " + getsymfolder();
            system(command.c_str());
        }
        void initializer::createprofilefile()
        {
            string command = "touch " + getprofilefile();
            system(command.c_str());
        }
        void initializer::createattachmentfolder()
        {
            string command = "mkdir " + getsymfolder() + "/attachments";
            system(command.c_str());
        }
        void initializer::createtaskfile()
        {
            string command = "touch " + gettaskfile();
            system(command.c_str());
        }
        void initializer::createtagfile()
        {
            string command = "touch " + gettagfile();
            system(command.c_str());
        }
        void initializer::createnotesfolder()
        {
            string command = "mkdir " + getsymfolder() + "/notes";
            system(command.c_str());
        }
        void initializer::encrypttaskfile()
        {
            crypto::aes128 aes;
            aes.encryptfile(gettaskfile(),getencryptedtaskfile(),password);
        }
        void initializer::decrypttaskfile()
        {
            crypto::aes128 aes;
            aes.decryptfile(getencryptedtaskfile(),gettaskfile(),password);
        }
        bool initializer::isencrypted()
        {
            ifstream checker;
            checker.open(getencryptedtaskfile());
            if(!checker)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool initializer::isNumber(const std::string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
        bool initializer::isproperlydecrypted()
    {
        ifstream checker;
        checker.open(gettaskfile());
        if(!checker)
        {
            return false;
        }
        else
        {
            string part;
            getline(checker,part,'^');
            if(isNumber(part))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
        void initializer::setprofilevalues()
        {
             ofstream profile;
             profile.open(getprofilefile());
                profile << "Name: " << name << endl;
                profile << "Phone Number: " << phone << endl;
                profile << "Email: " << email << endl;
                profile << "Address: " << address << endl;
                profile.close();

        }
        void initializer::initializetagfile()
        {
            ofstream tagfile;
            tagfile.open(gettagfile());
            tagfile << "1^important"<<endl;
            tagfile << "2^not-important"<<endl;
            tagfile.close();
        }
        void initializer::initialize()
            {
                if(!dotsymfolderchecker())
                {
                    cout << "\n\n\nNo .sym folder found in the home directory";
                    cout<< "\nInitializing for the first time\n";
                    cout << "Enter your full name: ";
                    getline(cin,name);
                    //cout <<endl;
                    cout << "Enter your phone number: ";
                    getline(cin,phone);
                    cout << "Enter your emaili address:";
                    getline(cin,email);
                    //cout<< endl;
                    cout<< "Enter your address(In one line): ";
                    getline(cin, address);
                    //cout<< name << " " << phone_number << " " << address << endl;
                    cout << "Enter a password to encrypt your task file: ";
                    //std::cout << "Enter password: ";

                    // Turn off terminal echoing
                    termios oldt;
                    tcgetattr(STDIN_FILENO, &oldt);
                    termios newt = oldt;
                    newt.c_lflag &= ~ECHO;
                    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

                    // Read the password
                    std::cin >> password;

                    // Restore terminal settings
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    std::cout << std::endl; // Move to the next line after password entry
                    cout << "Hello " << name << "!"<< endl;
                    system("sleep 2");
                    cout<< "We are now going to initialize your profile!" <<endl;
                    system("sleep 2");
                    system("clear");
                    createdirstructure();
                    setprofilevalues();
                    initializetagfile();



                }
                else
                {
                    return;
                    //cout<<"You have already initialized your symple tasker"<<endl;
                }
            }
} // core
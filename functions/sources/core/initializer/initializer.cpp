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
        string initializer::enterpassword()
        {
            std::cout << "Enter password: ";

            // Turn off terminal echoing
            termios oldt;
            tcgetattr(STDIN_FILENO, &oldt);
            termios newt = oldt;
            newt.c_lflag &= ~ECHO;
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);

            // Read the password
            if(cin.peek() == '\n')
            {
                cin.ignore();
            }
            string _password;
            std::cin >> _password;
            passwordanalyzer(_password);

            // Restore terminal settings
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            std::cout << std::endl; // Move to the next line after password entry
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
            //createtaskfile();
            createencryptedtaskfile();
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
            int tocheck = aes.encryptfile(gettaskfile(),getencryptedtaskfile(),password);
            if(tocheck == -1)
            {
                throw couldntencrypterrr();
            }
        }
        void initializer::decrypttaskfile()
        {
            crypto::aes128 myaes;
            //cout << password<< endl;
            myaes.decryptfile(getencryptedtaskfile(),gettaskfile(),password);
            if(!isproperlydecrypted())
            {
                throw couldntdecrypterrr();
            }
        }
        void initializer::createencryptedtaskfile()
        {
            string command = "touch " + getencryptedtaskfile();
            system(command.c_str());
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
            getline(checker,part);
            if(part == "0^ZGVtbw==^ZGVtbw==^bm90LWltcG9ydGFudA==^MDEvMDEvMjAwMA==^TlVMTA==^")
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
             if(!profile)
             {
                 throw filenotcreated();
             }
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
            if(!tagfile)
            {
                throw filenotcreated();
            }
            tagfile << "1^important"<<endl;
            tagfile << "0^not-important"<<endl;
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
                    cout << "Enter your email address:";
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
                    string _password;
                    std::cin >> _password;
                    passwordanalyzer(_password);

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
                    initializeencryptedtaskfile();
                }
                else
                {
                    return;
                    //cout<<"You have already initialized your symple tasker"<<endl;
                }
            }
        void initializer::initializeencryptedtaskfile()
        {
            //enterpassword();
            std::string mytempfile = gettaskfile();
            ofstream tempfile(mytempfile);
            string inputstring = "0^ZGVtbw==^ZGVtbw==^bm90LWltcG9ydGFudA==^MDEvMDEvMjAwMA==^TlVMTA==^";
            tempfile << inputstring << endl ;
            tempfile.close();
            crypto::aes128 myaes;
            //cout << password << endl;
            //cout << mytempfile << endl;
            //cout << getencryptedtaskfile() << endl;
            myaes.encryptfile(mytempfile,getencryptedtaskfile(),password);
            remove(mytempfile.c_str());
            myaes.decryptfile(getencryptedtaskfile(),gettaskfile(),password);
            cout << "done" << endl;

        }
    void initializer::passwordanalyzer(string _password)
    {
          int len = _password.length();
          //cout << "Password: " << len << endl;
          if(len > 16)
          {
              password = _password.substr(0, 16);
          }
          else if(len<16)
          {
              password = _password;
              for(int i = 16-len;i>0;i--)
              {
                  //cout<< "i: " << i << endl;
                  password+='#';
              }
          }
          else
          {
              password = _password;
          }
    }
    void initializer::cleanup()
    {
          cout << "Are you sure you want to delete all your data? (y/n): ";
            string input;
            cin >> input;
            if(input == "y")
            {
                cout << "Cleaning up..." << endl;
                sleep(1);
                remove(gettaskfile().c_str());
                remove(getencryptedtaskfile().c_str());
                remove(getprofilefile().c_str());
                remove(gettagfile().c_str());
                string command = "rm -rf " + getsymfolder() + "/attachments";
                system(command.c_str());
                command = "rm -rf " + getsymfolder() + "/notes";
                system(command.c_str());
                command = "rm -rf " + getsymfolder();
                system(command.c_str());
                cout << "Done" << endl;
                cout << "Thank you for using Symple Tasker" << endl;
                sleep(1);
                system("clear");
                exit(0);
            }
            else
            {
                return;
            }
    }
    void initializer::exithandler()
    {
        system("sleep 1");
        cout << "Encrypting your data" << endl;
        system("sleep 1");
        encrypttaskfile();
        remove(gettaskfile().c_str());
        cout << "Exiting the program" << endl;
        system("sleep 1");
        system("clear");
        exit(0);
    }


} // core
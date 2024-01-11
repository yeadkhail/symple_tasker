//
// Created by yead on 1/11/24.
//

#include "../../../../headers/inputhandler.h"
#include "vector"

using namespace std;

namespace core {
    inputhandler::inputhandler(){
        filename = PathManager::gettaskfile();
    }
    void inputhandler::deleteTask()
    {
        if(cin.peek() == '\n'){
            cin.ignore();
        }
        cout << "What task do you want to delete? >> ";
        string deleteTaskName;
        cin >> deleteTaskName;

        ifstream fin(filename);
        if(!fin)
        {
            cout << "Error while opening file" << endl;
            exit(1);
        }
        vector<string> lines;
        string line;
        while(getline(fin, line))
        {
            lines.push_back(line);
        }

        ofstream fout(filename);
        if(!fout)
        {
            cout << "Error while opening file" << endl;
            exit(1);
        }
        for(int i=0; i<lines.size(); i++)
        {
            line = lines[i];
            std::istringstream iss(line);
            std::string part;
            getline(iss, part, '^');
            getline(iss, part, '^');
            string name = crypto::base64::decode(part);
            if(deleteTaskName == name)
                continue;
            fout << lines[i] << endl;
        }

    }
    void inputhandler::editTask()
    {
        bool components[5] = {false};
        string yn;
        if(cin.peek() == '\n'){
            cin.ignore();
        }
        cout << "What task do you want to edit? >> ";
        string editTaskName;
        cin >> editTaskName;

        string inputName, inputDet, inputTag, inputDate, inputAtt;
        while(true)
        {
            cout << "Continue edit? (y/n) >> ";    cin >> yn;
            if(yn == "n")
                break;
            cout << "What do you wanna edit of this task?(name/details/tag/date/attachment) >> ";
            string editComponent;
            cin >> editComponent;

            cout << "Enter edited value of " << editComponent << " >> ";
            if(editComponent == "name") {
                components[0] = true;
                cin >> inputName;
            }else if(editComponent == "details") {
                components[1] = true;
                cin >> inputDet;
            }else if(editComponent == "tag") {
                components[2] = true;
                cin >> inputTag;
            }else if(editComponent == "date") {
                components[3] = true;
                cin >> inputDate;
            }else if(editComponent == "attachment"){
                components[4] = true;
                cin >> inputAtt;
            }
        }

        ifstream fin(filename);
        if(!fin)
        {
            cout << "Error while opening file" << endl;
            exit(1);
        }
        vector<string> lines;
        string line;
        while(getline(fin, line))
        {
            lines.push_back(line);
        }

        ofstream fout(filename);
        if(!fout)
        {
            cout << "Error while opening file" << endl;
            exit(1);
        }
        for(int i=0; i<lines.size(); i++)
        {
            line = lines[i];
            std::istringstream iss(line);
            std::string part;
            getline(iss, part, '^');
            string id = part;
            getline(iss, part, '^');
            string name = crypto::base64::decode(part);
            getline(iss, part, '^');
            string det = crypto::base64::decode(part);
            getline(iss, part, '^');
            string tag = crypto::base64::decode(part);
            getline(iss, part, '^');
            string date = crypto::base64::decode(part);
            getline(iss, part, '^');
            string att = crypto::base64::decode(part);
            if(editTaskName == name)
            {
                if(components[0] == false)
                    inputName = name;
                if(components[1] == false)
                    inputDet = det;
                if(components[2] == false)
                    inputTag = tag;
                if(components[3] == false)
                    inputDate = date;
                if(components[4] == false)
                    inputAtt = att;
                string final = id + "^";
                final += crypto::base64::encode(inputName) + "^";
                final += crypto::base64::encode(inputDet) + "^";
                final += crypto::base64::encode(inputTag) + "^";
                final += crypto::base64::encode(inputDate) + "^";
                final += crypto::base64::encode(inputAtt) + "^";
                fout << final << endl;
                continue;
            }
            fout << lines[i] << endl;
        }
    }

} // core
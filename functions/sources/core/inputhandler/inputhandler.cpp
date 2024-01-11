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

    }

} // core
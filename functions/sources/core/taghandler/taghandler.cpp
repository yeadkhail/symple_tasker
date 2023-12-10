//
// Created by yead on 11/6/23.
//

#include "../../../../headers/taghandler.h"

namespace core {
    taghandler::taghandler(string _tagname,int _importance)
    {
        tagname = _tagname;
        importance = _importance;
    }
    taghandler::taghandler()
    {
        tagname = "";
        importance = 0;
    }
    taghandler::taghandler(const string& line)
    {
        importance = stoi(line.substr(0,line.find_first_of('^')));
        tagname = line.substr(line.find_first_of('^')+1);
    }
    string taghandler::gettagname()
    {
        return tagname;
    }
    int taghandler::getimportance() const
    {
        return importance;
    }
    void taghandler::inserttag()
    {
        ofstream tagfile;
        tagfile.open(gettagfile(),ios::app);
        tagfile<<importance<<"^"<<tagname<<endl;
        tagfile.close();
    }
    bool taghandler::isTagExist(string tagname)
    {
        ifstream tagfile;
        tagfile.open(gettagfile());
        string line;
        while(getline(tagfile,line))
        {
            if(line.substr(line.find_first_of('^')+1) == tagname)
            {
                return true;
            }
        }
        return false;
    }
    bool taghandler::isimportant(string tagname)
    {
        ifstream tagfile;
        string home = getenv("HOME");
        std::string Sym = "/.sym";
        string symfolder = home + Sym;
        string tagfilename = symfolder + "/tags";
        tagfile.open(tagfilename);
        string line;
        while(getline(tagfile,line))
        {
            if(line.substr(line.find_first_of('^')+1) == tagname)
            {
                if(line.substr(0,line.find_first_of('^')) == "1")
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool taghandler::isimportant()
    {
        if(importance == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
} // core
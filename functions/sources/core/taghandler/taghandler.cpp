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
    taghandler::taghandler(string line)
    {
        importance = stoi(line.substr(0,line.find_first_of('^')));
        tagname = line.substr(line.find_first_of('^')+1);
    }
    string taghandler::gettagname()
    {
        return tagname;
    }
    int taghandler::getimportance()
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
} // core
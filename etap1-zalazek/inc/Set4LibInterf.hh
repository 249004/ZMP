#pragma once
#include <map>
#include <memory>
#include "LibInterf.hh"

using namespace std;

typedef map<string, shared_ptr<LibInterf>> LipMapInterf; //mapowanie

class Set4LibInterf
{
    LipMapInterf map_library;

    public:

        Set4LibInterf();
        ~Set4LibInterf();
        void add_library(string path);
        shared_ptr<LibInterf> find(string name);
};

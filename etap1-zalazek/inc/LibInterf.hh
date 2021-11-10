#pragma once
#include <string>
#include <map>
#include "Interp4Command.hh"

using namespace std;

class LibInterf
{
    void* handler; //uchwyt do biblioteki

    public:

        LibInterf(string path);
        ~LibInterf();
        string library_name;
        bool library_load(string path);
        bool library_init();

        Interp4Command *(*create_cmd)(void);
};
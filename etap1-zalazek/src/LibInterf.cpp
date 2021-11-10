#include "LibInterf.hh"
#include <dlfcn.h>
#include <iostream>


LibInterf::LibInterf(string path)
{
    library_load(path);
    library_init();
}

LibInterf::~LibInterf()
{
    dlclose(this->handler);
}

bool LibInterf::library_load(string path)  //zaladowanie biblioteki
{
    this->handler = dlopen(path.c_str(), RTLD_LAZY);

    if (this->handler == nullptr) {
        cerr << "Brakuje biblioteki " << path << endl;
        return false;
    }

    cout << "Załadowano bibliotekę " << path << endl;
    return true;

}

bool LibInterf::library_init() //inicjalizacja biblioteki
{
    void *new_command = dlsym(this->handler, "CreateCmd");

    if (new_command == nullptr) {
        cerr << "Nie znaleziono funkcji CreateCmd!" << endl;
        return false;
    }

    create_cmd = reinterpret_cast<Interp4Command* (*)(void)>(new_command); 
    Interp4Command* command = create_cmd();
    this->library_name = command->GetCmdName();
    delete command;
    return true;
}


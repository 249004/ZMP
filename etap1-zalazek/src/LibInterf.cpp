#include "LibInterf.hh"

/*! \brief Konstruktor klasy LibInterf
 *   
 * Odbywa się załadowanie biblioteki na podstawie podanej ścieżki.
 * \param path ścieżka do biblioteki
 */
LibInterf::LibInterf(string path)
{
    handler = dlopen(path.c_str(), RTLD_LAZY);
    if (!handler) 
        cerr << "Brakuje biblioteki " << path << endl;

    void *new_command = dlsym(handler, "CreateCmd");
    if (!new_command) 
        cerr << "Nie znaleziono funkcji CreateCmd!" << endl;

    create_cmd = reinterpret_cast<Interp4Command* (*)(void)>(new_command); 
    Interp4Command* command = create_cmd();
    library_name = command->GetCmdName();
    delete command;
}

LibInterf::~LibInterf()
{
    dlclose(handler);
}
#include "Set4LibInterf.hh"

using namespace std; 

Set4LibInterf::Set4LibInterf()
{
  add_library("libs/libInterp4Move.so");
  add_library("libs/libInterp4Set.so");
  add_library("libs/libInterp4Rotate.so");
  add_library("libs/libInterp4Pause.so");
}

Set4LibInterf::~Set4LibInterf() {}

  
/*! \brief Funkcja odpowiada za dodawanie biblioteki 
 *  Dodawanie biblioteki, która znajduje się pod podaną ścieżką
 * 
 * \param path ścieżka pod którą znajduje się biblioteka
 */
void Set4LibInterf::add_library(string path) 
{
  shared_ptr<LibInterf> library_ptr = make_shared<LibInterf>(path);
  this->map_library.insert({library_ptr->library_name, library_ptr});
}

/*! \brief Funkcja odpowiada za wyszukiwanie biblioteki 
 * Funkcja wyszukuje bibliotekę oraz sprawdza poprawność wykonanej operacji
 *
 * \param library_name nazwa szukanej biblioteki
 */
shared_ptr<LibInterf> Set4LibInterf::find(string library_name) 
{
  auto helper = this->map_library.find(library_name);

  if (helper == map_library.end()) 
    return nullptr;
  
  return (helper->second);
  
}
#include "Set4LibInterf.hh"

using namespace std; 

/*! Konstruktor Set4LibInterf
 * 
 */
Set4LibInterf::Set4LibInterf()
{
  add_library("libs/libInterp4Move.so");
  add_library("libs/libInterp4Set.so");
  add_library("libs/libInterp4Rotate.so");
  add_library("libs/libInterp4Pause.so");
}


/*! Destruktor Set4LibInterf
 * 
 */
Set4LibInterf::~Set4LibInterf() {}

  
/*! Funkcja odpowiada za dodawanie biblioteki 
 *  
 */
void Set4LibInterf::add_library(string path) 
{
  shared_ptr<LibInterf> library_ptr = make_shared<LibInterf>(path);
  this->map_library.insert({library_ptr->library_name, library_ptr});
}

/*! Funkcja odpowiada za wyszukiwanie biblioteki 
 * 
 */
shared_ptr<LibInterf> Set4LibInterf::find(string library_name) 
{
  auto helper = this->map_library.find(library_name);

  if (helper == map_library.end()) 
    return nullptr;
  
  return (helper->second);
  
}
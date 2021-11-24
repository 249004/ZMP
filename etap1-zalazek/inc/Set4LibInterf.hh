#ifndef SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <sstream>
#include <memory>
#include "LibInterf.hh"
#include "Scena.hh"
#include "klient.hh"

#define LINE_SIZE 500

using namespace std;

/*!                                                                             
 * \file                                                                        
 * \brief Klasa, która pozwala na wyszukiwanie i dodawanie bibliotek                            
 *                                                                              
 * Klasa przechowująca ścieżki do bibliotek, pozwala na ich wyszukiwanie oraz dodawanie.                                                                                                                         
 *                                                                              
 */
class Set4LibInterf
{
private:
  
    map<string, LibInterf*> Lib_list;
    Scena *scena;

public:
 
  Set4LibInterf(map<string, MobileObj*> &Obj_list);
  ~Set4LibInterf();

  /*! \brief Dodawanie biblioteki 
  *  
  */
  void add_library(string path);

  /*! \brief Funkcja odpowiadająca za uruchomienie preprocesora.
  *  
  */
  bool ExecPreprocessor(string NazwaPliku, istringstream &IStrm4Cmds);

  /*! \brief Funkcja odpowiada za czytanie komend.
  *
  */
  bool ReadCommands(istringstream &Strm_in, int socket);
  Scena *getScena() {return this->scena;}
};

#endif
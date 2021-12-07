#ifndef SET4LIBINTERF_HH
#define SET4LIBINTERF_HH

#include <sstream>
#include <memory>
#include "LibInterf.hh"
#include "Scena.hh"
#include "klient.hh"

#define LINE_SIZE 500

using namespace std;

/*!                                                                             
 * \file                                                                        
 * \brief Klasa, która pozwala na uruchomienie preprocesora oraz czytanie komend.                           
 *                                                                              
 * Klasa przechowująca ścieżki do bibliotek, pozwala na ich wyszukiwanie oraz dodawanie, a także uruchomienie preprocesora oraz czytanie komend.                                                                                                                       
 *                                                                              
 */
class Set4LibInterf
{

  /*! \brief Lista komend.
   *  
   */
  map<string, LibInterf*> Lib_list;

  /*! \brief Wsakźnik na obiekt klasy Scena.
   *  
   */
  Scena *scena;
  
public:
 
  /*! \brief Konstruktor klasy Set4LibInterf.
  *  
  */
  Set4LibInterf(map<string, MobileObj*> &Obj_list);
  
  ~Set4LibInterf();

  /*! \brief Dodawanie biblioteki.
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
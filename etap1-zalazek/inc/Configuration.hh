#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "MobileObj.hh"

using namespace std;

/*!
 * \file
 * \brief Definicja klasy Configuration.
 *
 * Plik zawiera definicję klasy Configuration, 
 * która przechowuje konfigurację sceny i listę bibliotek, 
 * odczytywana z pliku XML.
 */

class Configuration {

  /*! \brief Mapa obiektów mobilnych.
   * 
   */
  map<string, MobileObj*> ObjectsList;

  /*! \brief Lista bibliotek.
   * 
   */
  vector<string> LibrariesList;

  public:
  ~Configuration(){ObjectsList.clear();}

  /*! \brief Funkcja odpowiadająca za dodawanie biblioteki do listy.
   * 
   */
  void AddLib(const string &LibName);

  /*! \brief Funkcja odpowiadająca za dodawanie nowego obiektu.
   * 
   */
  void AddObj(const string &Name, const Vector3D &Scale,const string &RGB, const Vector3D &Shift, const Vector3D &RotXYZ_deg, const Vector3D &Trans_m);

 /*! \brief Metoda zwracająca biblioteki, które są dostępne jako wektor.
  * 
  */
  vector<string> & GetLib_list() {return this->LibrariesList;}
  
 /*! \brief Metoda zwracająca biblioteki, które są dostępne jako mapa.
  * 
  */
  map<string, MobileObj*> & GetObj_list() {return this->ObjectsList;}

};


#endif

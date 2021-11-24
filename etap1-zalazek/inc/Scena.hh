#pragma once
#include <vector>
#include <map>
#include <string>
#include "MobileObj.hh"
#include "AccessControl.hh"

using namespace std;

/*!                                                                             
 * \file                                                                        
 * \brief Scena na której pojawiają się obiekty                              
 *                                                                              
 * Klasa opcjonalna, która jest sceną, na której to mogą pojawić się obiekty                                                                                                                           
 *                                                                              
 */

class Scena : public AccessControl
{

  /*! \brief Mapa wskaźników na obiekty klasy MobileObj 
   *  
   */
  map<string, MobileObj*> Obj_list;

public:

    Scena(map<string, MobileObj*> &mob_obj);
    ~Scena();

    /*! \brief Funkcja wyszukująca obiekt.
     *  
     * \param pMobObj nazwa szukanego obiektu
     */
   MobileObj* FindMobileObj(string pMobObj);

    /*! \brief Funkcja dodająca obiekt.
     *  
     * \param pMobObj nazwa dodawanego obiektu
     */
    void AddMobileObj(string pMobObj);
    
     /*! \brief Mapa, w którym są wszystkie wskażniki obiektów znajdujących się na scenie.
      * 
      */
    map<string, MobileObj*> GetObj_list(){return this->Obj_list;}
 
     /*! \brief Wektor, w którym są wszystkie obiekty znajdujące się na scenie.
      * 
      */
    vector<MobileObj*> getObj();
   
    
};




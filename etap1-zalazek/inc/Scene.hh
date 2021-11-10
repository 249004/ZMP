#pragma once
#include <map>
#include <string>
#include <memory>
#include "MobileObj.hh"

using namespace std;

/*!                                                                             
 * \file                                                                        
 * \brief Scena na której pojawiają się obiekty                              
 *                                                                              
 * Klasa opcjonalna, która jest sceną, na której to mogą pojawić się obiekty                                                                                                                           
 *                                                                              
 */


typedef map<string, shared_ptr<MobileObj>> Mobile_Obj;

class Scene
{   
  /*! \brief Obiekt mobilny pojawiający się na scenie 
   *  
   */
  Mobile_Obj mob_obj;

  public:
    Scene();
    ~Scene();

    /*! \brief Funkcja wyszukująca obiekt
     *  
     */
    shared_ptr<MobileObj> FindMobileObj(string pMobObj);

    /*! \brief Funkcja dodająca obiekt
     *  
     */
    void AddMobileObj(MobileObj *pMobObj);
};

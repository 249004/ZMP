#include "Scena.hh"

Scena::Scena(map<string, MobileObj*> &mob_obj) : Obj_list(mob_obj)
{
 
 cout << "Została stworzona scena z " << Obj_list.size() << " obiektami" << endl;
  
}

Scena::~Scena() {Obj_list.clear();}

/*! \brief Funkcja wyszukująca obiekt.
  * Funkcja pozwalająca na wyszukiwanie obiektu.
  * 
  * \param pMobObj nazwa wyszukiwanego obiektu
  */
MobileObj* Scena::FindMobileObj(string pMobObj)
{
  map<string, MobileObj*>::iterator it = this->Obj_list.find(pMobObj);

  if (it == this->Obj_list.end()) 
    return nullptr;
  else 
    return (it->second);
}

/*! \brief Funkcja dodająca obiekt.
  * Funkcja pozwalająca na dodanie obiektu.
  * 
  * \param pMobObj nazwa dodawanego obiektu
  */
void Scena::AddMobileObj(string pMobObj)
{
  MobileObj *Objptr = new MobileObj;
  this->Obj_list.insert({pMobObj, Objptr});
}

/*! \brief Wektor, w którym są wszystkie obiekty znajdujące się na scenie.
 * 
 */
vector<MobileObj*> Scena::getObj()
{
    vector<MobileObj*> Vec;
    map<string, MobileObj *>::iterator it;

    for(it = Obj_list.begin(); it!=Obj_list.end(); it++) {
        Vec.push_back(it->second);
    }
    return Vec; 
}

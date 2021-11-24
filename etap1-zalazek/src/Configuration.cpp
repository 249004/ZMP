#include "Configuration.hh"

/*! \brief Dodawanie biblioteki do listy.
 * 
 */
void Configuration::AddLib(const string &LibName)
{
  this->LibrariesList.push_back(LibName);
}

/*! \brief Dodawanie nowego obiektu wraz z wartościami go opisującymi.
 *  Funkcja odpowiadająca za dodawanie obiektu razem z informacjami takimi jak:
 *  
 * \param Name pełna nazwa obiektu
 * \param Shift odpowiada parametrowi T_shift - pozwala na zmianę lokalizacji układu współrzędnych obiektu
 * \param Scale zawiera współczynniki skali względem poszczególnych osi
 * \param RotXYZ_deg zawiera wartości kątów
 * \param Trans_m odpowiada parametrowi T_trans - wektor translacji, finalna pozycja obiektu
 * \param RGB zadaje kolor obiektu we współrzędnych RGB
 */
void Configuration::AddObj(const string &Name, const Vector3D &Scale, const string &RGB, const Vector3D &Shift, const Vector3D &RotXYZ_deg, const Vector3D &Trans_m)
{
  MobileObj* Obj = new MobileObj;
  Obj->SetName(Name.c_str());
  Obj->SetShift(Shift);
  Obj->SetScale(Scale);
  Obj->SetAng_Pitch_deg(RotXYZ_deg[0]);
  Obj->SetAng_Roll_deg(RotXYZ_deg[1]);
  Obj->SetAng_Yaw_deg(RotXYZ_deg[2]);
  Obj->SetPosition_m(Trans_m);
  Obj->SetColor(RGB);

  this->GetObj_list().insert({Name, Obj});
}

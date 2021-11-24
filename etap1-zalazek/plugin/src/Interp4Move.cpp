#include <iostream>
#include "Interp4Move.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


/*!
 *
 */
Interp4Move::Interp4Move(): _Speed_mmS(0), road_length(0)
{}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  cout << GetCmdName() << " Obj_A " << _Speed_mmS  << " " << road_length << endl;
}


/*!
 *
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}


/*! \brief Funkcja odpowiadająca za wykonywanie polecenia.
 *
 */
bool Interp4Move::ExecCmd( MobileObj  *pMobObj,  int Socket) const //AccessControl *pAccCtrl 
{
  /*int it = std::floor(this->road_length/this->_Speed_mmS);
  int Dir = this->_Speed_mmS > 0 ? 1 : -1;
  
  for (int i = 0; i < it; ++i) {
    pAccCtrl->LockAccess();
    double Ang = pMobObj->GetAng_Roll_deg();
    Vector3D Pos = pMobObj->GetPosition_m();

    Pos[0]+=this->_Speed_mmS*Dir*cos(M_PI*Ang/180);
    Pos[1]+=this->_Speed_mmS*Dir*sin(M_PI*Ang/180);
    
    pMobObj->SetPosition_m(Pos);
    pAccCtrl->MarkChange();
    pAccCtrl->UnlockAccess();
    usleep(100000);
  }*/
  return true;
}


/*! Wczytywanie parametrow
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{

  Strm_CmdsList >> _Speed_mmS >> road_length;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  Dlugosc_drogi[m]" << endl;
}

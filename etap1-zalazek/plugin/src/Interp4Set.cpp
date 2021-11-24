#include <iostream>
#include "Interp4Set.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Set"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}


/*!
 *
 */
Interp4Set::Interp4Set(): x(0), y(0), OX(0), OY(0), OZ(0)
{}


/*!
 *
 */
void Interp4Set::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " Obj_A " << x << " " << y << " " << OX << "" << OY << " " << OZ << endl;
}


/*!
 *
 */
const char* Interp4Set::GetCmdName() const
{
  return ::GetCmdName();
}


/*! \brief Funkcja odpowiadająca za wykonywanie polecenia.
 *
 */
bool Interp4Set::ExecCmd( MobileObj  *pMobObj,  int Socket) const //AccessControl *pAccCtrl 
{
  /*
  pAccCtrl->LockAccess();
  Vector3D NewPos = pMobObj->GetPositoin_m();

  NewPos[0] = this->x;
  NewPos[1] = this->y;
  
  pMobObj->SetPosition_m(NewPos);
  pMobObj->SetAng_Roll_deg(OX);
  pMobObj->SetAng_Pitch_deg(OY);
  pMobObj->SetAng_Yaw_deg(OZ);

  pAccCtrl->MarkChange();
  pAccCtrl->UnlockAccess();
  usleep(300000);*/

  return true;
}


/*! wczytywanie parametrów
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> x >> y >> OX >> OY >> OZ;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}


/*!
 *
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  NazwaObiektu  Wsp_X  Wsp_Y Kat_OX[stopnie] Kat_OY[stopnie] Kat_OZ[stopnie]" << endl;
}

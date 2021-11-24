#include <iostream>
#include "Interp4Rotate.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Rotate"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}


/*!
 *
 */
Interp4Rotate::Interp4Rotate(): ang_speed(0), axis(""), rot_angle(0)
{}


/*!
 *
 */
void Interp4Rotate::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " Obj_A " << ang_speed  << " " << axis << " " << rot_angle << endl;
}


/*!
 *
 */
const char* Interp4Rotate::GetCmdName() const
{
  return ::GetCmdName();
}


/*! \brief Funkcja odpowiadająca za wykonywanie polecenia.
 *
 */
bool Interp4Rotate::ExecCmd( MobileObj  *pMobObj, int Socket) const //AccessControl *pAccCtrl 
{
  /*
  char Axis = this->AxisName.at(1);
  double AngleRPY;
  int Dir = this->ang_speed > 0 ? 1 : -1;
  double NewPoint = AngleRPY + this->rotation_angle * Dir;
  
  switch (Axis)
  {
    case 'X':
      AngleRPY = pMobObj->GetAng_Roll_deg();
      break;

    case 'Y':
      AngleRPY = pMobObj->GetAng_Pitch_deg();
      break;

    case 'Z':
      AngleRPY = pMobObj->GetAng_Yaw_deg();
      break;
  }

  while (NewPoint != AngleRPY)
  {
    pAccCtrl->LockAccess();
    AngleRPY += this->ang_speed;

    if (Dir == 1)
    {
      if (AngleRPY > NewPoint)
        AngleRPY = NewPoint;
    }
    else
    {
      if (AngleRPY < NewPoint)
        AngleRPY = NewPoint;
    }

    switch (Axis)
    {
    case 'X':
      pMobObj->SetAng_Roll_deg(AngleRPY);
      break;

    case 'Y':
      pMobObj->SetAng_Pitch_deg(AngleRPY);
      break;

    case 'Z':
      pMobObj->SetAng_Yaw_deg(AngleRPY);
      break;
    }

    pAccCtrl->MarkChange();
    pAccCtrl->UnlockAccess();
    usleep(100000);
  }*/
  
  return true;
}


/*! wczytywanie parametrów
 *
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{

  Strm_CmdsList >> ang_speed >> axis >> rot_angle;
  return !Strm_CmdsList.fail();

}


/*!
 *
 */
Interp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}


/*!
 *
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate NazwaObiektu Szybkosc_katowa[stopnie/sekunde] Nazwa_osi Kat_obrotu[stopnie]"<< endl;
}

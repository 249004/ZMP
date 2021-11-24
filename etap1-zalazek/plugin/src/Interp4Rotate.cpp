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
bool Interp4Rotate::ExecCmd( MobileObj  *pMobObj, int Socket) const
{
   
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

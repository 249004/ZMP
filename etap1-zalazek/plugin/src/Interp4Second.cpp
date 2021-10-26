#include <iostream>
#include "Interp4Second.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Second"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Second::CreateCmd();
}


/*!
 *
 */
Interp4Second::Interp4Second(): _Speed_mmS(0)
{}


/*!
 *
 */
void Interp4Second::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " Obj_A " << _Speed_mmS  << " 10" << endl;
}


/*!
 *
 */
const char* Interp4Second::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Second::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Second::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
Interp4Command* Interp4Second::CreateCmd()
{
  return new Interp4Second();
}


/*!
 *
 */
void Interp4Second::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

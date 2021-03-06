#include <iostream>
#include "Interp4Pause.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Pause"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Pause::CreateCmd();
}


/*!
 *
 */
Interp4Pause::Interp4Pause(): delay(0)
{}


/*!
 *
 */
void Interp4Pause::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " Obj_A " << " "  << delay << endl;
}


/*!
 *
 */
const char* Interp4Pause::GetCmdName() const
{
  return ::GetCmdName();
}


/*! \brief Funkcja odpowiadająca za wykonywanie polecenia.
 *
 */
bool Interp4Pause::ExecCmd( MobileObj  *pMobObj, AccessControl *pAccCtrl ) const //AccessControl *pAccCtrl 
{
  pAccCtrl->LockAccess();
  usleep(delay*1000);
  pAccCtrl->UnlockAccess();

  return true;
}


/*!
 *
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
  
  Strm_CmdsList >> delay;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Pause::CreateCmd()
{
  return new Interp4Pause();
}


/*!
 *
 */
void Interp4Pause::PrintSyntax() const
{
  cout << "   Pause Czas_pauzy[ms]"<< endl;
}

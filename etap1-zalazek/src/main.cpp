#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "Interp4Command.hh"
#include "MobileObj.hh"

using namespace std;


int main()
{
  void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFunMove;

  void *pLibHnd_Second = dlopen("libInterp4Second.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Second)(void);
  void *pFunSecond;


  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
    return 1;
  }

  if (!pLibHnd_Second) {
    cerr << "!!! Brak biblioteki: Interp4Second.so" << endl;
    return 1;
  }


  pFunMove = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFunMove) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }

  pFunSecond = dlsym(pLibHnd_Second,"CreateCmd");
  if (!pFunSecond) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }

  pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFunMove);
  pCreateCmd_Second = *reinterpret_cast<Interp4Command* (**)(void)>(&pFunSecond);

  Interp4Command *pCmdMove = pCreateCmd_Move();
  Interp4Command *pCmdSecond = pCreateCmd_Second();

  cout << endl;
  cout << pCmdMove->GetCmdName() << endl;
  cout << endl;
  pCmdMove->PrintSyntax();
  cout << endl;
  pCmdMove->PrintCmd();
  cout << endl;
  
  cout << endl;
  cout << pCreateCmd_Second->GetCmdName() << endl;
  cout << endl;
  pCreateCmd_Second->PrintSyntax();
  cout << endl;
  pCreateCmd_Second->PrintCmd();
  cout << endl;

  delete pCmdMove;
  delete pCreateCmd_Second;

  dlclose(pLibHnd_Move);
  dlclose(pLibHnd_Second);


}

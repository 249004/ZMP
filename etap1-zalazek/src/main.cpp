#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <cstdio>
#include <sstream>
#include "Interp4Command.hh"
#include "MobileObj.hh"

#define LINE_SIZE 500

using namespace std;

bool ExecPreprocessor(const char *NazwaPliku, istringstream &IStrm4Cmds)
{
  string Cmd4Preproc = "cpp -P ";
  char Line[LINE_SIZE];
  ostringstream OTmpStrm;

  Cmd4Preproc += NazwaPliku;
  FILE* pProc = popen(Cmd4Preproc.c_str(),"r");

  if (!pProc) return false;

  while (fgets(Line, LINE_SIZE, pProc))
  {
    OTmpStrm << Line;
  }

  IStrm4Cmds.str(OTmpStrm.str());
  return pclose(pProc) == 0;
}

int main()
{
  void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFun;

  void *pLibHnd_Set= dlopen("libInterp4Set.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Set)(void);

  void *pLibHnd_Rotate= dlopen("libInterp4Rotate.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Rotate)(void);

  void *pLibHnd_Pause= dlopen("libInterp4Pause.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Pause)(void);

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
    return 1;
  }

  if (!pLibHnd_Set) {
    cerr << "!!! Brak biblioteki: Interp4Set.so" << endl;
    return 1;
  }

  if (!pLibHnd_Rotate) {
    cerr << "!!! Brak biblioteki: Interp4Rotate.so" << endl;
    return 1;
  }

  if (!pLibHnd_Pause) {
    cerr << "!!! Brak biblioteki: Interp4Pause.so" << endl;
    return 1;
  }


  pFun = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);

  pFun = dlsym(pLibHnd_Set,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Set = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);

  pFun = dlsym(pLibHnd_Rotate,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Rotate = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);

  pFun = dlsym(pLibHnd_Pause,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Pause = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);


  Interp4Command *pCmd = pCreateCmd_Move();


  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  

  pCmd = pCreateCmd_Set();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;


  pCmd = pCreateCmd_Rotate();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;


  pCmd = pCreateCmd_Pause();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;

  delete pCmd;

  dlclose(pLibHnd_Move);
  dlclose(pLibHnd_Set);
  dlclose(pLibHnd_Rotate);
  dlclose(pLibHnd_Pause);

  istringstream strumien;
  ExecPreprocessor("program_dzialan.cmd",strumien);

  cout<< endl << strumien.str();


}

#include <sstream>
#include <cassert>
#include "MobileObj.hh"
#include "Set4LibInterf.hh"
#include "xmlinterp.hh"
#include "Configuration.hh"
#include "klient.hh"
#include <iostream>

using namespace std;

int main(int argc, char* args[])
{
  istringstream Stream_in;
  Configuration config;

  cout << "Port: " << PORT << endl;

  int Socket4Sending;

  if(ReadFile("config/config.xml",config) == false)
  {
    cerr << "Czytanie pliku nie powiodło się."<<endl;
    return 1;
  }

  map<string, MobileObj*> objectsList = config.GetObj_list();
  Set4LibInterf *LibraryList = new Set4LibInterf(objectsList);

  if(!OpenConnection(Socket4Sending))
     return 1;
  else 
    cout << "Połączenie powiodło się." << endl;

  Sender _Sender(Socket4Sending, LibraryList->getScena());
  thread Thread4Sending(Fun_CommunicationThread, &_Sender);
  LibraryList->ExecPreprocessor("program_dzialan.cmd", Stream_in);
  LibraryList->ReadCommands(Stream_in,Socket4Sending);

  close(Socket4Sending, _Sender, move(Thread4Sending));
  
  return 0;
}

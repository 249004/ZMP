#include <sstream>
#include <cassert>
#include "MobileObj.hh"
#include "Set4LibInterf.hh"
#include "xmlinterp.hh"
#include "Configuration.hh"
#include "klient.hh"
#include <iostream>

using namespace std;

int main()
{
  istringstream Stream_in;
  Configuration config;
  int Socket4Send;

  cout << "Port: " << PORT << endl; //moze do wywalenia
  
  if(ReadFile("config/config.xml",config) == false) {
    cerr << "Czytanie pliku nie powiodło się."<<endl;
    return 1;
  }

  map<string, MobileObj*> objects_list = config.GetObject_list();
  Set4LibInterf *libraries_list = new Set4LibInterf(objects_list);

  if(!OpenConnection(Socket4Send))
     return 1;
  else 
    cout << "Połączenie się powiodło." << endl;

  Sender *sender_ = new Sender(Socket4Send, libraries_list->getScena());
  libraries_list->ExecPreprocessor("program_dzialan.cmd", Stream_in);
  libraries_list->ReadCommands(Stream_in, Socket4Send);
  
  return 0;
}


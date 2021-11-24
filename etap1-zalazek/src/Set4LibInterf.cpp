#include "Set4LibInterf.hh"

Set4LibInterf::Set4LibInterf(map<string, MobileObj*> &Obj_list)
{
    this->scena = new Scena(Obj_list);
    add_library("libs/libInterp4Move.so");
    add_library("libs/libInterp4Set.so");
    add_library("libs/libInterp4Rotate.so");
}

Set4LibInterf::~Set4LibInterf() 
{ 
  Lib_list.clear();
  if(scena != nullptr) 
    delete scena;}

/*! \brief Funkcja odpowiada za dodawanie biblioteki 
 *  Dodawanie biblioteki, która znajduje się pod podaną ścieżką
 * 
 * \param path ścieżka pod którą znajduje się biblioteka
 */
void Set4LibInterf::add_library(string path)
{
    LibInterf *library_ptr = new LibInterf(path);
    Lib_list.insert({library_ptr->library_name, library_ptr});
}

/*! \brief Uruchomienie preprocesora.
 *  
 * \param NazwaPliku nazwa wczytywanego pliku poleceń
 * \param IStrm4Cmds podawany strumień 
 */
bool Set4LibInterf::ExecPreprocessor(string NazwaPliku, istringstream &IStrm4Cmds)
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

 /*! \brief Funkcja odpowiadająca za czytanie komend.
  *
  * \param Strm_in - strumień utworzony przez preprocesor
  */
bool Set4LibInterf::ReadCommands (istringstream &Strm_in, int socket)
{
  string command_name;
  string object_name;
  bool flag;

  vector<MobileObj*> Obj_list = this->getScena()->getObj();
  
  Send(socket,"Clear\n");
  for(MobileObj* _objectPtr : Obj_list) {
    string info =  _objectPtr->returnParameters();
    Send(socket,info.c_str());
    cout << info << endl;
  }

  while (Strm_in >> command_name) 
  {
    if(command_name!= "Pause") Strm_in >> object_name;
    
    flag = true;
    map<string, LibInterf*>::iterator it = this->Lib_list.find(command_name);
    if (it == this->Lib_list.end())
    {
      cerr << "Komenda  " << command_name << "nie została znaleziona." << endl;
      flag = false;
    }
      
    if(flag)
    {
      Interp4Command *command = it->second->create_cmd();
      if (!command->ReadParams(Strm_in))
      {
        cerr << "Nie udało się wczytać parametrów." << command_name << endl;
        delete command;
        return false;
      }
      MobileObj* MobObj = this->scena->FindMobileObj(object_name);
      if(MobObj == nullptr)
      {
        cerr << "Nie znaleziono obiektu " << object_name << endl;
        delete command;
        return false;
      }
    
      command->PrintCmd();
      delete command;
    }
    
  }
  return true;
}
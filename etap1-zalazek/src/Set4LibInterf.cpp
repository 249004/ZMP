#include "Set4LibInterf.hh"

Set4LibInterf::Set4LibInterf(map<string, MobileObj*> &Obj_list)
{
    this->scena = new Scena(Obj_list);
    add_library("libs/libInterp4Move.so");
    add_library("libs/libInterp4Set.so");
    add_library("libs/libInterp4Rotate.so");
    add_library("libs/libInterp4Pause.so");
}

Set4LibInterf::~Set4LibInterf() 
{ 
  Lib_list.clear();
  if(scena != nullptr) 
    delete scena;
}

/*! \brief Funkcja odpowiada za dodawanie biblioteki 
 *  Dodawanie biblioteki, która znajduje się pod podaną ścieżką
 * 
 * \param[in] path ścieżka pod którą znajduje się biblioteka
 */
void Set4LibInterf::add_library(string path)
{
    LibInterf *library_ptr = new LibInterf(path);
    Lib_list.insert({library_ptr->library_name, library_ptr});
}

/*! \brief Uruchomienie preprocesora.
 *  
 * \param[in] NazwaPliku nazwa wczytywanego pliku poleceń
 * \param[in] IStrm4Cmds podawany strumień 
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
  * \param[in] Strm_in - strumień utworzony przez preprocesor
  */
bool Set4LibInterf::ReadCommands (istringstream &Strm_in, int socket)
{
  string command_name;
  string object_name;
  bool flag;
  string info = "Clear \n";

  vector<MobileObj*> list_obj = this->getScena()->getObj();

  for(MobileObj* pObj : list_obj) {
    info += "AddObj " + pObj->returnParameters();
  }

  const char *cmd_config = info.c_str();
  Send(socket, cmd_config);

  while (Strm_in >> command_name) //sprawdzenie czy w strumieniu jest jakas komenda
  {
    vector<thread *> list_thr;

    while (command_name != "End_Parallel_Actions")
    {

      if(command_name != "Pause" && command_name != "Begin_Parallel_Actions") 
        Strm_in >> object_name;
      
      flag = true;
      map<string, LibInterf*>::iterator it = this->Lib_list.find(command_name);

      if (it == this->Lib_list.end())
      {
        cerr << "Komenda " << command_name << "nie została znaleziona." << endl;
        flag = false;
      }
        
      if(flag)
      {
        Interp4Command *command = it->second->create_cmd();

        if (!command->ReadParams(Strm_in)) {

          cerr << "Nie udało się wczytać parametrów." << command_name << endl;
          delete command;
          return false;
        }

        MobileObj* MobObj = this->scena->FindMobileObj(object_name);

        if(MobObj == nullptr) {

          cerr << "Nie znaleziono obiektu " << object_name << endl;
          delete command;
          return false;
        }
        else {

          command->PrintCmd();
          thread* new_thread = new thread(&Interp4Command::ExecCmd, command, MobObj, this->scena);
          list_thr.push_back(new_thread);
        }
    
      }
      Strm_in >> command_name;

    }

    for (thread *objThr : list_thr) { //oczekiwanie na zakonczenie wszystkich zadan
      objThr->join();
      delete objThr;
    }

  }
  return true;
  
}
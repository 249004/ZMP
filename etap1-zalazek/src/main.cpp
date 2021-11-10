#include <sstream> 
#include <cassert>
#include "MobileObj.hh"
#include "Set4LibInterf.hh"
#include "Scene.hh"
/*#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include "xmlinterp.hh"
#include <list>*/


#define LINE_SIZE 500

using namespace std;

/*! Uruchomienie preprocesora
 *  
 *
 */
bool ExecPreprocessor(string NazwaPliku, istringstream &IStrm4Cmds)
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


bool ExecProgram(string file_name)
{
  Set4LibInterf lib;
  Scene scene;
  istringstream in_stream;
  string command_name;
  string object_name;


  ExecPreprocessor(file_name, in_stream);


  while (in_stream >> command_name)
  {
    in_stream >> object_name;

    auto library = lib.find(command_name); //szukanie pluginu
    if (library == nullptr) {//sprawdzenie poprawnosci
      cout << "Komenda " << command_name <<  " nie została znaleziona" << endl;
      return false;
    }

    auto command = library->create_cmd(); //tworzenie interpretera
    if(false == command->ReadParams(in_stream)) { //wczytywanie parametrów i sprawdzenie poprawnosci
      cout << "Nie udało się wczytać parametrów" << endl;
      delete command;
      return false;
    }

    auto object = scene.FindMobileObj(object_name); //szukanie obiektu
    if (library == nullptr) { //sprawdzenie poprawnosci
     cout << "Nie znaleziono obiektu: " << object_name << endl;
      delete command;
      return false;
    }

    command->PrintCmd();
    command->ExecCmd(object.get(), 0); //jesli wszystko poszlo dobrze wykona się operacja
    delete command;
  }

  return true;
}


/*!
 * Czyta z pliku opis poleceń i dodaje je do listy komend,
 * które robot musi wykonać.
 * \param sFileName - (\b we.) nazwa pliku z opisem poleceń.
 * \param CmdList - (\b we.) zarządca listy poleceń dla robota.
 * \retval true - jeśli wczytanie zostało zrealizowane poprawnie,
 * \retval false - w przeciwnym przypadku.
 *//*
bool ReadFile(const char* sFileName, Configuration &rConfig)
{
   try {
            XMLPlatformUtils::Initialize();
   }
   catch (const XMLException& toCatch) {
            char* message = XMLString::transcode(toCatch.getMessage());
            cerr << "Error during initialization! :\n";
            cerr << "Exception message is: \n"
                 << message << "\n";
            XMLString::release(&message);
            return 1;
   }

   SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();

   pParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
   pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
   pParser->setFeature(XMLUni::fgXercesDynamic, false);
   pParser->setFeature(XMLUni::fgXercesSchema, true);
   pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

   pParser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

   DefaultHandler* pHandler = new XMLInterp4Config(rConfig);
   pParser->setContentHandler(pHandler);
   pParser->setErrorHandler(pHandler);

   try {
     
     if (!pParser->loadGrammar("config/config.xsd",
                              xercesc::Grammar::SchemaGrammarType,true)) {
       cerr << "!!! Plik grammar/actions.xsd, '" << endl
            << "!!! ktory zawiera opis gramatyki, nie moze zostac wczytany."
            << endl;
       return false;
     }
     pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse,true);
     pParser->parse(sFileName);
   }
   catch (const XMLException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            cerr << "Informacja o wyjatku: \n"
                 << "   " << sMessage << "\n";
            XMLString::release(&sMessage);
            return false;
   }
   catch (const SAXParseException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

            cerr << "Blad! " << endl
                 << "    Plik:  " << sSystemId << endl
                 << "   Linia: " << Exception.getLineNumber() << endl
                 << " Kolumna: " << Exception.getColumnNumber() << endl
                 << " Informacja: " << sMessage 
                 << endl;

            XMLString::release(&sMessage);
            XMLString::release(&sSystemId);
            return false;
   }
   catch (...) {
            cout << "Zgloszony zostal nieoczekiwany wyjatek!\n" ;
            return false;
   }

   delete pParser;
   delete pHandler;
   return true;
}*/


int main()
{

  //z zalazka lab3
  /*
  Configuration   Config;

  if (!ReadFile("config/Sconfig.xml",Config)) return 1;
  */


  if (true == ExecProgram("program_dzialan.cmd"))
    cout << "Praca programu zakończona pomyślnie." << endl;
  
  else
    cout << "Wystąpił błąd programu." << endl;
  


}
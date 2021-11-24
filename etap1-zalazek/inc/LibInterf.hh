#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH
#include <string>
#include <map>
#include "Interp4Command.hh"
#include <dlfcn.h>
#include <iostream>

using namespace std;

/*!                                                                             
 * \file                                                                        
 * \brief Klasa, która dostarcza opcji dla bibliotek.                          
 *                                                                              
 * Klasa pozwalająca na operacje na bibliotekach.                                                                                                                    
 *                                                                              
 */



class LibInterf
{
    /*! \brief Uchwyt do biblioteki 
     *  
     */
    void *handler;

public:

    LibInterf(string path);
    ~LibInterf();

    /*! \brief Nazwa biblioteki 
     *  
     */
    string library_name;

    /*! \brief Metoda tworząca obiekt klasy Interp4Command, służacy do modelowania polecenia 
     *  
     */
    Interp4Command *(*create_cmd)(void);
};
#endif
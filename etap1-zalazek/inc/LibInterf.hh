#ifndef LIBINTERF_HH
#define LIBINTERF_HH
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

    /*! \brief Konstuktor klasy LibInterf
     *  
     */
    LibInterf(string path);

    /*! \brief Destruktor klasy LibInterf
     *  
     */
    ~LibInterf();

    /*! \brief Nazwa biblioteki 
     *  
     */
    string library_name;

    /*! \brief Metoda tworząca obiekt klasy Interp4Command, służący do modelowania polecenia.
     *  
     */
    Interp4Command *(*create_cmd)(void);
};
#endif
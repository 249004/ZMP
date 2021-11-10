#pragma once
#include <string>
#include <map>
#include "Interp4Command.hh"

using namespace std;

/*!                                                                             
 * \file                                                                        
 * \brief Klasa, która dostarcza opcji dla bibliotek                             
 *                                                                              
 * Klasa pozwalająca na operacje na bibliotekach                                                                                                                        
 *                                                                              
 */


class LibInterf
{
    /*! \brief Uchwyt do biblioteki 
     *  
     */
    void* handler;

    public:

        LibInterf(string path);
        ~LibInterf();

        /*! \brief Nazwa biblioteki 
         *  
         */
        string library_name;

        /*! \brief Zaladowanie biblioteki 
         *  
         */
        bool library_load(string path);

        /*! \brief Inicjalizacja biblioteki 
         *  
         */
        bool library_init();

        Interp4Command *(*create_cmd)(void);
};
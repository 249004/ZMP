#pragma once
#include <map>
#include <memory>
#include "LibInterf.hh"

using namespace std;

/*!                                                                             
 * \file                                                                        
 * \brief Klasa, która pozwala na wyszukiwanie i dodawanie bibliotek                            
 *                                                                              
 * Klasa przechowująca ścieżki do bibliotek, pozwala na ich wyszukiwanie oraz dodawanie.                                                                                                                         
 *                                                                              
 */

typedef map<string, shared_ptr<LibInterf>> LibMapInterf; //mapowanie

class Set4LibInterf
{
    /*! \brief Zmapowana biblioteka
     *  
     */
    LibMapInterf map_library;

    public:

        Set4LibInterf();
        ~Set4LibInterf();

        /*! \brief Dodawanie biblioteki 
         *  
         */
        void add_library(string path);

        /*! \brief Wyszukiwanie biblioteki 
         *  
         */
        shared_ptr<LibInterf> find(string name);
};

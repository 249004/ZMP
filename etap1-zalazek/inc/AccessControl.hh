#ifndef ACCESSCONTROLL_HH
#define ACCESSCONTROLL_HH

#include <mutex>

/*!
 * \file
 * \brief Zawiera definicję klasy AccessControl
 */


/*!
 * \brief Przechowuje deskryptor gniazda
 *
 *  Przechowuje deskryptor gniazda wraz z obiektem klasy std::mutex,
 *  który powinien być wykorzystany nadzorca wyłącznego dostępu
 *  do sceny oraz gniazda połączenia sieciowego z serwerem.
 */
class AccessControl {
   /*!
    * \brief Zapewnia wyłączny dostęp do obiektu w trakcie modyfikacji.
    */
    std::mutex   _Guard;

    /*!
    * \brief Przechowuje deskryptor pliku skojarzonym z połączeniem
    *        sieciowym z serwerem.
    *
    * Przechowuje deskryptor pliku skojarzonym z połączeniem
    * sieciowym z serwerem.
    * Wartość poprawnego deskrytora musi być różna od 0.
    */ 
    int         _Socket = 0;

   /*!
    * \brief Przechowuje informacje o zmianie.
    *
    * Przechowuje informacje o tym czy zmiana nastąpiła (\p true) czy też
    * nie (\p false).
    */ 
    bool         _Changed = false;
   /*!
    * \brief Wykorzystywany do blokowania całej sceny.
    */
    std::mutex  _ExternalGuard;
 public:

   /*!
   * \brief Udostępnia deskryptor pliku skojarzonego z połączeniem
   *        sieciowym z serwerem.
   *
   *  Udostępnia deskryptor skojarzonego z połączeniem sieciowym z serwerem.
   * \return Deskryptor pliku.
   */
   int GetSocket() const { return _Socket; }
   
  /*!
   * \brief Dostęp do informacji o zmianie.
   *
   * Dostęp do informacji o zmianie.
   * \retval true - gdy zmiana nastąpiła.
   * \retval false - w przypadku przeciwnym.
   */
   bool IsChanged() const { return _Changed; }
  /*!
   * \brief Zaznaczenie, że zmiana nastąpiła.
   */
   void MarkChange() { _Guard.lock();  _Changed = true;  _Guard.unlock(); }
  /*!
   * \brief Skasowanie informacji, że zmiana nastąpiła.
   */
   void CancelChange() { _Guard.lock();  _Changed = false;  _Guard.unlock(); }
  /*!
   * \brief Zamyka dostęp całej sceny.
   */
   void LockAccess() { _ExternalGuard.lock(); }
  /*!
   * \brief Otwiera dostęp do całej sceny.
   */
   void UnlockAccess() { _ExternalGuard.unlock(); } 
};




#endif 

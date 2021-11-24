#ifndef MOBILEOBJ_HH
#define MOBILEOBJ_HH

#include <string>
#include <sstream>
#include "Vector3D.hh"

/*!
 * \file
 * \brief Zawiera definicję klasy MobileObj
 *
 * Plik zawiera definicję klasy MobileObj.
 * Definicja to może być rozszerzona i zmienione mogą
 * być nazwy pól. Obowiązkowe są jedynie nazwy metod.
 */

/*!
    * Nazwy pól klasy są jedynie propozycją i mogą być zmienione
    * Nazwy metod są obowiązujące.
    */
class MobileObj
{
        /*!
        * \brief Kąt \e yaw reprezentuje rotację zgodnie z ruchem wskazówek zegara
        *        wokół osi \e OZ.
	*
	* Kąt \e yaw reprezentuje rotację zgodnie z ruchem wskazówek zegara
        * wokół osi \e OZ. Wartość kąta wyrażona jest w stopniach.
        */
        double _Ang_Yaw_deg = 0;

        /*!
        * \brief Kąt \e pitch reprezentuje rotację zgodnie z ruchem wskazówek zegara
        *        wokół osi \e OY.
	*
	* Kąt \e pitch reprezentuje rotację zgodnie z ruchem wskazówek zegara
        * wokół osi \e OY. Wartość kąta wyrażona jest w stopniach.
        */
        double _Ang_Pitch_deg = 0;

        /*!
        * \brief Kąt \e roll reprezentuje rotację zgodnie z ruchem wskazówek zegara
        *        wokół osi \e OX.
	*
	* Kąt \e roll reprezentuje rotację zgodnie z ruchem wskazówek zegara
        * wokół osi \e OX. Wartość kąta wyrażona jest w stopniach.
        */
        double _Ang_Roll_deg = 0;

        /*!
        * \brief Współrzędne aktualnej pozycji obiektu.
	*
	* Współrzędne aktualnej pozycji obiektu. Przyjmuje się,
	* że współrzędne wyrażone są w metrach.
        */
        Vector3D _Position_m;

        /*!
        * \brief Nazwa obiektu, która go indentyfikuje.
        *
        * Nazwa obiektu, która go indentyfikuje. Z tego względu musi
        * musi to być nazwa unikalna wśród wszystkich obiektów na scenie.
        */
        std::string _Name;

        /*!
        * \brief Wektor, który odpowiada parametrowi T_shift.
        *
        * Pozwala na zmianę lokalizacji układu współrzednych obiektu, który domyślnie 
        * znajduje się w ich geometrycznym środku.
        */
       Vector3D Shift;

        /*!
        * \brief Wektor, który zawiera współczynniki skali względem poszczególnych osi
        *
        * Wartości te nie mogą być ujemne.
        */
       Vector3D Scale;

        /*!
        * \brief Zmienna przetrzymująca informacje o kolorze obiektu.
        *
        * Wykorzystywane są do tego współrzedne RGB.
        */
       int Color [3];

public:
       /*!
       * \brief Udostępia wartość kąta \e roll.
       *
       * Udostępia wartość kąta \e roll. Jest ona wyrażona w stopniach.
       */
        double GetAng_Roll_deg() const { return _Ang_Roll_deg; }
        /*!
       * \brief Udostępia wartość kąta \e pitch.
       *
       * Udostępia wartość kąta \e pitch. Jest ona wyrażona w stopniach.
       */
        double GetAng_Pitch_deg() const { return _Ang_Pitch_deg; }
        /*!
       * \brief Udostępia wartość kąta \e yaw.
       *
       * Udostępia wartość kąta \e yaw. Jest ona wyrażona w stopniach.
       */
        double GetAng_Yaw_deg() const { return _Ang_Yaw_deg; }

        /*!
       * \brief Zmienia wartość kąta \e roll.
       *
       * Zmienia wartość kąta \e roll.
       * \param[in] Ang_Roll_deg - nowa wartość kąta \e roll wyrażona w stopniach.
       */
        void SetAng_Roll_deg(double Ang_Roll_deg) { _Ang_Roll_deg = Ang_Roll_deg; }
        /*!
       * \brief Zmienia wartość kąta \e pitch.
       *
       * Zmienia wartość kąta \e pitch.
       * \param[in] Ang_Pitch_deg - nowa wartość kąta \e pitch wyrażona w stopniach.
       */
        void SetAng_Pitch_deg(double Ang_Pitch_deg) { _Ang_Pitch_deg = Ang_Pitch_deg; }
        /*!
       * \brief Zmienia wartość kąta \e yaw.
       *
       * Zmienia wartość kąta \e yaw.
       * \param[in] Ang_Yaw_deg - nowa wartość kąta \e yaw wyrażona w stopniach.
       */
        void SetAng_Yaw_deg(double Ang_Yaw_deg) { _Ang_Yaw_deg = Ang_Yaw_deg; }

        /*!
       * \brief Udostępnia współrzędne położenia obiektu w trybie tylko do odczytu.
       *
       * Udostępnia współrzędne punktu, który definiuje położenia obiektu
       * w trybie tylko do odczytu.
       * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
       */
        const Vector3D &GetPositoin_m() const { return _Position_m; }
        /*!
       * \brief Udostępnia współrzędne położenia obiektu w trybie modyfikacji.
       *
       * Udostępnia współrzędne punktu, który definiuje położenia obiektu
       * w trybie modyfikacji.
       * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
       */
        Vector3D &UsePosition_m() { return _Position_m; }
        /*!
       * \brief Zmienia współrzędne położenia obiektu.
       *
       * Zmienia współrzędne punktu, który definiuje położenia obiektu.
       * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
       * \param[in] rPos_m - współrzędne nowgo położenia. Przyjmuje się,
       *                     że są one wyrażone w metrach.
       */
        void SetPosition_m(const Vector3D &rPos_m) { _Position_m = rPos_m; }

        /*!
       * \brief Zmienia nazwę obiektu.
       *
       *  Zmienia nazwę obiektu.
       *  \param[in] sName - nowa nazwa obiektu.
       */
        void SetName(const char *sName) { _Name = sName; }
        /*!
        * \brief Udostępnia nazwę obiektu.
	*
	* Udostępnia nazwę obiektu w trybie tylko do odczytu.
        */
        const std::string &GetName() const { return _Name; }

                /*!
         * \brief Zwraca informację o stanie obiektu
         * 
         * \return ciag znaków zawierający informacje o obiekcie.
         */
        std::string ActualPosition()
        {
                char buff[10];
                int len = sprintf(buff, " Name=%s RotXYZ_deg=(%f,%f,%f)\n", this->_Name.c_str(), this->_Ang_Yaw_deg, this->_Ang_Pitch_deg, this->_Ang_Roll_deg);
                std::string result(buff, len);

                return result;
        }

        std::string returnParameters()
        {
                std::string info = "AddObj";
                char buff[200];
                int len = sprintf(buff, " Name=%s RGB=(%d,%d,%d) Scale=(%f,%f,%f) Shift=(%f,%f,%f) RotXYZ_deg=(%f,%f,%f), Trans_m=(%f,%f,%f)\n",
                this->_Name.c_str(), this->Color[0], this->Color[1], this->Color[2],this->Scale[0],this->Scale[1],this->Scale[2],
                this->Shift[0],this->Shift[1],this->Shift[2],this->_Ang_Roll_deg,this->_Ang_Pitch_deg,this->_Ang_Yaw_deg,this->_Position_m[0], this->_Position_m[1],this->_Position_m[2]);
                std::string result(buff, len);
                info = info+result;
                return info;          
        }

       /*!
       * \brief Zmienia parametr T_shift obiektu.
       *
       *  Zmienia lokalizację układu współrzędnych obiektu.
       *  \param Shift - nowy parametr obiektu
       */
        void SetShift(const Vector3D &Shift)
        {
                this->Shift = Shift;
        }


       /*!
       * \brief Zmienia skalę.
       *
       *  Zmienia współczynniki skali względem poszczególnych osi.
       *  \param Scale - nowa skala
       */
        void SetScale(const Vector3D &Scale)
        {
                this->Scale = Scale;
        }

       /*!
       * \brief Zmienia kolor obiektu.
       *
       *  Zadaje kolor obiektu we współrzędnych RGB.
       *  \param RGB - nowy kolor obiektu
       */
        void SetColor(const std::string RGB)
        {
                std::istringstream str;

                str.str(RGB);
                str >> this->Color[0] >> this->Color[1] >> this->Color[2];
        }

};

#endif

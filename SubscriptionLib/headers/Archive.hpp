/* 
 * File:   Archive.hpp
 * Author: Pawel
 *
 * Deklaracja klasy Archive
 * Created on 8 styczeń 2011, 16:56
 */

#ifndef ARCHIVE_HPP
#define	ARCHIVE_HPP

#include <string>

namespace SubscriptionLib
{
    /*
     * Klasa bazowa dla archiwow, do których serializowane i deserializowane sa wiadomosci
     */
    class Archive {
    public:
        /*
         * Destruktor
         */
        virtual ~Archive();
        /*
         * Pobranie z serializowanej wiadomosci
         * @return zserailizwona wiadomosc
         */
        virtual std::string getStr() const = 0;
        /*
         * Pobranie dlugosci naglowka wiadomosci
         * @return dlugosc naglowka
         */
        virtual int getSizeLength() const = 0;
        /*
         * Zapisanie parametru do ciagu bedacego serializowana wiadomoscia
         * @param Wiadomosc
         */
        virtual Archive& operator<< (const std::string& str) = 0;
        /*
         * Odczytanie parametru z zserializowanej wiadomosci
         * @param Wiadomosc
         */
        virtual Archive& operator>> (std::string& str) = 0;
        /*
         * Zapisanie parametru do ciagu bedacego serializowana wiadomoscia
         * @param Wiadomosc
         */
        virtual Archive& operator<< (const int& i) = 0;
        /*
         * Odczytanie parametru z zserializowanej wiadomosci
         * @param Wiadomosc
         */
        virtual Archive& operator>> (int& i) = 0;
    protected:
        Archive();
    };
}
#endif	/* ARCHIVE_HPP */


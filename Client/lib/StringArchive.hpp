/* 
 * File:   StringArchive.hpp
 * Author: Pawel
 *
 * Deklaracja klasy StringArchive
 * Created on 8 styczeń 2011, 16:58
 */

#ifndef STRINGARCHIVE_HPP
#define	STRINGARCHIVE_HPP

#include "Archive.hpp"
#include <list>

#define SIZELENGTH 8

namespace SubscriptionLib
{
    /*
     * Archiwum, w ktorym serializacja i deserializacja odbywa sie do ciagu znakow
     */
    class StringArchive: public Archive {
    public:
        /*
         * Konstruktor
         */
        StringArchive();
        /*
         * Konstruktor
         * @param str Wiadomosc, ktora bedzie deserializowana
         */
        StringArchive(const std::string& str);
        /*
         * Destruktor
         */
        virtual ~StringArchive();
        virtual std::string getStr() const;
        virtual int getSizeLength() const;
        virtual Archive& operator<< (const std::string& str);
        virtual Archive& operator>> (std::string& str);
        virtual Archive& operator<< (const int& i);
        virtual Archive& operator>> (int& i);

        
    private:
        std::list<std::string> _strs;
        static std::string _delimiter;
        static int _sizeLength;
        void format(std::string& str) const;
        void removeEmpty(std::list<std::string>& strs) const;
    };
}

#endif	/* STRINGARCHIVE_HPP */


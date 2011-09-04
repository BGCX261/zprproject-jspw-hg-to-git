/* 
 * File:   ExceptionLib.hpp
 * Author: Pawel
 *
 * Deklaracja klasy ExceptionLib
 * Created on 7 styczeń 2011, 21:07
 */

#ifndef EXCEPTIONLIB_HPP
#define	EXCEPTIONLIB_HPP

#include <string>
#include <exception>
#include <boost/format.hpp>

namespace SubscriptionLib
{
    /*
     * Reprezentuje wyjatek
     */
    class Exception : public std::exception {
    public:
        /*
         * Konstruktor
         */
        Exception();
        /*
         * Konstruktor
         * @param str Wiadomosc
         */
        Exception(const std::string& str);
        /*
         * Konstruktor
         * @param format Wiadomosc
         */
        Exception(const boost::format& format);
        /*
         * Destruktor
         */
        virtual ~Exception() throw();
    private:
        std::string _str;
    };
}

#endif	/* EXCEPTIONLIB_HPP */


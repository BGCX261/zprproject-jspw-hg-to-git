/* 
 * File:   Exception.hpp
 * Author: Pawel
 *
 * Deklaracja klasy ExceptionClient
 * Created on 27 listopad 2010, 20:40
 */

#ifndef EXCEPTIONCLIENT_HPP
#define	EXCEPTIONCLIENT_HPP

#include <exception>
#include <boost/format.hpp>

namespace Client
{
    /*
     * Reprezentuje wyjatek w aplikacji klienckiej
     */
    class ExceptionClient: public std::exception {
    public:
        /*
         * Konstruktor
         */
        ExceptionClient();
        /*
         * Konstruktor
         * @param msg Wiadomosc
         */
        ExceptionClient(const std::string& msg);
        /*
         * Konstruktor
         * @param format Wiadomosc
         */
        ExceptionClient(const boost::format& format);
        /*
         * Konstruktor kopiujacy
         * @param orig Kopiowany obiekt
         */
        ExceptionClient(const ExceptionClient& orig);
        /*
         * Destruktor
         */
        virtual ~ExceptionClient() throw();
        /*
         * Pobiera tresc wiadomosci
         * @return Wiadomosc
         */
        virtual const char* what() const throw();
    private:
        std::string _message;
    };
}

#endif	/* EXCEPTIONCLIENT_HPP */


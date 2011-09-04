/* 
 * File:   Terminal.hpp
 * Author: Pawel
 *
 * Deklaracja klasy Terminal
 * Created on 27 listopad 2010, 20:43
 */

#ifndef TERMINAL_HPP
#define	TERMINAL_HPP

#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/format.hpp>
#include <string>
#include "Command.hpp"

namespace Client
{
    /*
     * Odpowiedzialna za czytanie/wyswietlanie danych z terminala
     * Singleton
     */
    class Terminal {
    public:
        typedef boost::shared_ptr<Terminal> PTerminal;

        /*
         * Pobranie instancji
         * @return Instacja
         */
        static PTerminal getInstance();
        /*
         * Destruktor
         */
        virtual ~Terminal();

        /*
         * Synchroniczne pobranie wiadomosci z konsoli
         * @return Pobrana wiadomosc
         */
        Command::PCommand readCmd();
        /*
         * Synchroniczne czytanie wprowadzoanych danych
         * @return Wprowadzone dane
         */
        std::string read();
        /*
         * Pisanie danych na konsole
         * @param str Dane do pisania
         */
        void write(const std::string& str);
        /*
         * Pisanie danych na konsole
         * @param format Dane do pisania
         */
        void write(const boost::format& format);

    private:
        static PTerminal _pInstance;

        Terminal();

        boost::mutex _mutex;
    };
}

#endif	/* TERMINAL_HPP */


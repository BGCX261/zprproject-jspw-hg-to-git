/* 
 * File:   CmdFactory.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klasy CmdFactory
 * Created on 26 listopad 2010, 20:41
 */

#ifndef CMDFACTORY_HPP
#define	CMDFACTORY_HPP

#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include "Command.hpp"

namespace Client
{
    /*
     * Fabryka obiektow typu Command. Obiekty tworzone sa na podstawie identyfikatora komendy.
     * Singleton
     */
    class CmdFactory {
    public:
        typedef Command::PCommand (*NewCmdFun)(const std::vector<std::string>&);
        typedef boost::shared_ptr<CmdFactory> PCmdFactory;

        /*
         * Destruktor
         */
        virtual ~CmdFactory();
        /*
         * Pobranie instancji obiektu
         * @return Instancja obiektu
         */
        static PCmdFactory getInstance();
        /*
         * Zarejestrowanie nowego typu komendy
         * @param key Identyfikator typu komendy
         * @param fun Funkcja tworzaca obiekt nowego typu komendy
         * @return Okresla czy udalo sie dodac nowy typ komendy
         */
        bool registerCmd(const std::string& key, NewCmdFun fun);
        /*
         * Utworzenie obiektu komendy wedlug klucza
         * @param key Identyfikator komendy, ktora ma byc utworzona
         * @param strs Parametr przekazany funkcji tworzacej obiekt znajdujacej sie w klasie danego typu
         * @return Utworzony obiekt komendy
         */
        Command::PCommand create(const std::string& key, const std::vector<std::string>& strs);
        /*
         * Utworzenie obiektu komendy
         * @param strs Element 0 tablicy musi byc kluczem typu, pozostale przekazane funkcji tworzacej obiekt znajdujacej sie w klasie danego typu
         * @return Utworzony obiekt komendy
         */
        Command::PCommand create(const std::vector<std::string>& strs);

    private:
        typedef std::map<std::string, NewCmdFun> Callbacks;

        Callbacks _callbacks;
        static PCmdFactory _pInstance;

        CmdFactory();
        Callbacks::const_iterator find(const std::string& key);
    };
}

#endif	/* CMDFACTORY_HPP */


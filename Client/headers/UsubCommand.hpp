/* 
 * File:   UsubCommand.hpp
 * Author: Pawel
 *
 * Deklaracja klasy UsubCommand
 * Created on 26 listopad 2010, 14:19
 */

#ifndef USUBCOMMAND_HPP
#define	USUBCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

namespace Client
{
    /*
     * Reprezentuje komende zaprzestania subskrypcji
     */
    class UsubCommand: public Command, public CommandThread {
    public:
        /*
         * Konstruktor
         * @param login Login
         * @param type Id subskrypcji
         * @param threadId Id watku
         */
        UsubCommand(std::string login, std::string type, int threadId);
        /*
         * Konstruktor kopiujacy
         * @param orig Kopiowana komenda
         */
        UsubCommand(const UsubCommand& orig);
        /*
         * Destruktor
         */
        virtual ~UsubCommand();
        /*
         * Tworzy obiekt klasy na podstawie dostarczonego parametru
         * @param strs Lista parametrow. 0 - threadId, 1 - login, 2 - password
         * @return Wskaznik na stworzony obiekt
         */
        static PCommand create(const std::vector<std::string>& strs);
        /*
         * Akceptuje wizytatora
         * @param visitor Akceptowany wizytator
         */
        virtual void accept(Visitor& visitor) const;
        /*
         * Pobranie id subskrypcji
         * @return Id subskrypcji
         */
        std::string getType() const;
        /*
         * Pobranie loginu
         * @return Login
         */
        std::string getLogin() const;
    private:
        std::string _login;
        std::string _type;
    };
}

#endif	/* USUBCOMMAND_HPP */


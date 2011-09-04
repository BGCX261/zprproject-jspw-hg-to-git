/* 
 * File:   SubsCommand.hpp
 * Author: Pawel
 *
 * Deklaracja klasy SubsCommand
 * Created on 26 listopad 2010, 14:16
 */

#ifndef SUBSCOMMAND_HPP
#define	SUBSCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

namespace Client
{
    /*
     * Reprezentuje komende dopisania do subskrypcji
     */
    class SubsCommand: public Command, public CommandThread {
    public:
        /*
         * Konstruktor
         * @param login Login
         * @type type id subskrypcji
         * @threadId Id watku
         */
        SubsCommand(std::string login, std::string type, int threadId);
        /*
         * Konstruktor kopiujacy
         * @param orig Kopiowana komenda
         */
        SubsCommand(const SubsCommand& orig);
        /*
         * Destruktor
         */
        virtual ~SubsCommand();
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
         * Pobranie loginu
         * @return Login
         */
        std::string getLogin() const;
        /*
         * Pobranie id subskrypcji
         * @return Id subskrypcji
         */
        std::string getType() const;
    private:
        std::string _login;
        std::string _type;
    };
}

#endif	/* SUBSCOMMAND_HPP */


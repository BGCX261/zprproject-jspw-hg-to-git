/* 
 * File:   NewMsgCommand.hpp
 * Author: Pawel
 *
 * Deklaracja klasy NewMsgCommand
 * Created on 11 styczeń 2011, 20:12
 */

#ifndef NEWMSGCOMMAND_HPP
#define	NEWMSGCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

namespace Client
{
    /*
     * Reprezentuje komende wyslania nowej wiadomosci do subskrypcji
     */
    class NewMsgCommand: public Command, public CommandThread {
    public:
        /*
         * Konstruktor
         * @param login Login uzytkownika
         * @param type Id subskrypcji
         * @param msg Waidomosc dodwanana
         * @param threadId Id watku
         */
        NewMsgCommand(std::string login, std::string type, std::string msg, int threadId);
        /*
         * Konstruktor kopiujacy
         * @param orig Kopiowana komenda
         */
        NewMsgCommand(const NewMsgCommand& orig);
        /*
         * Destruktor
         */
        virtual ~NewMsgCommand();
        /*
         * Tworzy obiekt klasy na podstawie dostarczonego parametru
         * @param strs Lista parametrow. 0 - threadId, 1 - login, 2 - id subskrypcji, od 3 wiadomosc
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
         * @return Is subskrypcji
         */
        std::string getType() const;
        /*
         * Pobranie wiadomosci
         * @return Dodawana wiadomosc
         */
        std::string getMsg() const;

    private:
        std::string _login;
        std::string _type;
        std::string _msg;
    };
}

#endif	/* NEWMSGCOMMAND_HPP */


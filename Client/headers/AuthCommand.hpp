/* 
 * File:   AuthCommand.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klasy AuthCommand
 * Created on 26 listopad 2010, 14:16
 */

#ifndef AUTHCOMMAND_HPP
#define	AUTHCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

namespace Client
{
    /*
     * Reprezntuje komende zalogowania watku na serwerze
     */
    class AuthCommand: public Command, public CommandThread {
    public:
        /*
         * Konstruktor
         * @param login Login uzytkownika
         * @param password Haslo uzytkownika
         * @param threadId Id watku klienta, ktory ma zostac zalogowany
         */
        AuthCommand(std::string login, std::string password, int threadId);
        /*
         * Konstruktor kopiujacy
         * @param orig Kopiowana komenda
         */
        AuthCommand(const AuthCommand& orig);
        /*
         * Destruktor
         */
        virtual ~AuthCommand();
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
         * Pobiera login uzytkownika
         * @return Login uzytkownika
         */
        std::string getLogin() const;
        /*
         * Pobiera haslo uzytkownika
         * @return Haslo uzytkownika
         */
        std::string getPasswd() const;

    private:
        std::string _login;
        std::string _password;
    };
}

#endif	/* AUTHCOMMAND_HPP */


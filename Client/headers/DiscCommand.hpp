/* 
 * File:   DiscCommand.hpp
 * Author: Pawel
 *
 * Deklaracja klasy DiscCommand
 * Created on 26 listopad 2010, 14:20
 */

#ifndef DISCCOMMAND_HPP
#define	DISCCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

namespace Client
{
    /*
     * Reprezentuje komende rozlaczenia klienta
     */
    class DiscCommand: public Command, public CommandThread {
    public:
        /*
         * Konstuktor
         * @param threadId Id watku
         */
        DiscCommand(int threadId);
        /*
         * Konstruktor kopiujacy
         * @param orig Kopiowana komenda
         */
        DiscCommand(const DiscCommand& orig);
        /*
         * Destruktor
         */
        virtual ~DiscCommand();
        /*
         * Tworzy obiekt klasy na podstawie dostarczonego parametru
         * @param strs Lista parametrow. 0 - threadId
         * @return Wskaznik na stworzony obiekt
         */
        static PCommand create(const std::vector<std::string>& strs);
        /*
         * Akceptuje wizytatora
         * @param visitor Akceptowany wizytator
         */
        virtual void accept(Visitor& visitor) const;
    private:
    };
}

#endif	/* DISCCOMMAND_HPP */


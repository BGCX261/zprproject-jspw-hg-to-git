/* 
 * File:   CreateCommand.hpp
 * Author: Pawel
 *
 * Deklaracja klasy CreateCommand
 * Created on 26 listopad 2010, 14:21
 */

#ifndef CREATECOMMAND_HPP
#define	CREATECOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

namespace Client
{
    /*
     * Reprezentuje komende stworzenia nowego watku klienta
     */
    class CreateCommand: public Command, public CommandThread {
    public:
        /*
         * Konstruktor
         * @param threadId Id tworzonego watku
         */
        CreateCommand(int threadId);
        /*
         * Konstruktor kopiujacy
         * @param orig Kopiowana komenda
         */
        CreateCommand(const CreateCommand& orig);
        /*
         * Destruktor
         */
        virtual ~CreateCommand();
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

#endif	/* CREATECOMMAND_HPP */


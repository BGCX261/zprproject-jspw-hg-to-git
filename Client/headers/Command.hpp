/* 
 * File:   Command.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klsy Command
 * Created on 26 listopad 2010, 14:15
 */

#ifndef COMMAND_HPP
#define	COMMAND_HPP

#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>

namespace Client
{
    class Visitor;

    /*
     * Typ abstrakcyjny, po ktorym dziedzicza wszytskie komendy wystepujace w kliencie
     */
    class Command {
    public:
        typedef boost::shared_ptr<Command> PCommand;

        /*
         * Destruktor
         */
        virtual ~Command();

        /*
         * Interfejs akceptujacy podany wizytatot
         * @param visitor Akceptowany wizytator
         */
        virtual void accept(Visitor& visitor) const = 0;
    protected:
        Command();
    };
}
#endif	/* COMMAND_HPP */


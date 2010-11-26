/* 
 * File:   SubsCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:16
 */

#ifndef SUBSCOMMAND_HPP
#define	SUBSCOMMAND_HPP

#include <Command.hpp>

class SubsCommand: public Command {
public:
    SubsCommand();
    SubsCommand(const SubsCommand& orig);
    virtual ~SubsCommand();

    static Command* create();
private:

};

#endif	/* SUBSCOMMAND_HPP */


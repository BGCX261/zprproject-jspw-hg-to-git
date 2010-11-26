/* 
 * File:   CreateCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:21
 */

#ifndef CREATECOMMAND_HPP
#define	CREATECOMMAND_HPP

#include <Command.hpp>

class CreateCommand: public Command {
public:
    CreateCommand();
    CreateCommand(const CreateCommand& orig);
    virtual ~CreateCommand();

    static Command* create();
private:

};

#endif	/* CREATECOMMAND_HPP */


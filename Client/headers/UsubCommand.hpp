/* 
 * File:   UsubCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:19
 */

#ifndef USUBCOMMAND_HPP
#define	USUBCOMMAND_HPP

#include <Command.hpp>

class UsubCommand: public Command {
public:
    UsubCommand();
    UsubCommand(const UsubCommand& orig);
    virtual ~UsubCommand();

    static Command* create();
private:

};

#endif	/* USUBCOMMAND_HPP */


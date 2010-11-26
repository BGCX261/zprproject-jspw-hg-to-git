/* 
 * File:   DiscCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:20
 */

#ifndef DISCCOMMAND_HPP
#define	DISCCOMMAND_HPP

class DiscCommand: public Command {
public:
    DiscCommand();
    DiscCommand(const DiscCommand& orig);
    virtual ~DiscCommand();

    virtual static Command* create();
private:

};

#endif	/* DISCCOMMAND_HPP */


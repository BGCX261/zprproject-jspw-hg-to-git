/* 
 * File:   Command.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:15
 */

#ifndef COMMAND_HPP
#define	COMMAND_HPP

class Command {
public:
    virtual static Command* create() = 0;
private:

};

#endif	/* COMMAND_HPP */


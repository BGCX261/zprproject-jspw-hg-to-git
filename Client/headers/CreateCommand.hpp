/* 
 * File:   CreateCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:21
 */

#ifndef CREATECOMMAND_HPP
#define	CREATECOMMAND_HPP

#include "Command.hpp"

class CreateCommand: public Command {
public:
    CreateCommand();
    CreateCommand(int threadId);
    CreateCommand(const CreateCommand& orig);
    virtual ~CreateCommand();

    static PCommand create(const std::vector<std::string>& strs);
private:
    int _threadId;
};

#endif	/* CREATECOMMAND_HPP */


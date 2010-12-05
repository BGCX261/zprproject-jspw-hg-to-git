/* 
 * File:   CreateCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:21
 */

#ifndef CREATECOMMAND_HPP
#define	CREATECOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

class CreateCommand: public Command, public CommandThread {
public:
    CreateCommand(int threadId);
    CreateCommand(const CreateCommand& orig);
    virtual ~CreateCommand();

    static PCommand create(const std::vector<std::string>& strs);
    virtual void accept(const Visitor& visitor) const;
private:
};

#endif	/* CREATECOMMAND_HPP */


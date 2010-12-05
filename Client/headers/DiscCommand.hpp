/* 
 * File:   DiscCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:20
 */

#ifndef DISCCOMMAND_HPP
#define	DISCCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

class DiscCommand: public Command, public CommandThread {
public:
    DiscCommand(int threadId);
    DiscCommand(const DiscCommand& orig);
    virtual ~DiscCommand();

    static PCommand create(const std::vector<std::string>& strs);
    virtual void accept(const Visitor& visitor) const;
private:
};

#endif	/* DISCCOMMAND_HPP */


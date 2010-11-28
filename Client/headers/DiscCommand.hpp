/* 
 * File:   DiscCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:20
 */

#ifndef DISCCOMMAND_HPP
#define	DISCCOMMAND_HPP

#include <Command.hpp>

class DiscCommand: public Command {
public:
    DiscCommand();
    DiscCommand(int threadId);
    DiscCommand(const DiscCommand& orig);
    virtual ~DiscCommand();

    static PCommand create(const std::vector<std::string>& strs);
private:
    int _threadId;
};

#endif	/* DISCCOMMAND_HPP */


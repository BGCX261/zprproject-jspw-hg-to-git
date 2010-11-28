/* 
 * File:   SubsCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:16
 */

#ifndef SUBSCOMMAND_HPP
#define	SUBSCOMMAND_HPP

#include "Command.hpp"

class SubsCommand: public Command {
public:
    SubsCommand();
    SubsCommand(std::string login, std::string type, int threadId);
    SubsCommand(const SubsCommand& orig);
    virtual ~SubsCommand();

    static PCommand create(const std::vector<std::string>& strs);
private:
    std::string _login;
    std::string _type;
    int _threadId;
};

#endif	/* SUBSCOMMAND_HPP */


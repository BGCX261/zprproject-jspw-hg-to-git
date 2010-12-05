/* 
 * File:   SubsCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:16
 */

#ifndef SUBSCOMMAND_HPP
#define	SUBSCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

class SubsCommand: public Command, public CommandThread {
public:
    SubsCommand(std::string login, std::string type, int threadId);
    SubsCommand(const SubsCommand& orig);
    virtual ~SubsCommand();

    static PCommand create(const std::vector<std::string>& strs);
    virtual void accept(const Visitor& visitor) const;
    std::string getLogin() const;
    std::string getType() const;
private:
    std::string _login;
    std::string _type;
};

#endif	/* SUBSCOMMAND_HPP */


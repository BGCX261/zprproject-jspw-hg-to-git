/* 
 * File:   UsubCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:19
 */

#ifndef USUBCOMMAND_HPP
#define	USUBCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

class UsubCommand: public Command, public CommandThread {
public:
    UsubCommand(std::string login, std::string type, int threadId);
    UsubCommand(const UsubCommand& orig);
    virtual ~UsubCommand();

    static PCommand create(const std::vector<std::string>& strs);
    virtual void accept(const Visitor& visitor) const;
    std::string getType() const;
    std::string getLogin() const;
private:
    std::string _login;
    std::string _type;
};

#endif	/* USUBCOMMAND_HPP */


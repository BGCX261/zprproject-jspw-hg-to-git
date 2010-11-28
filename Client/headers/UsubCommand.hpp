/* 
 * File:   UsubCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:19
 */

#ifndef USUBCOMMAND_HPP
#define	USUBCOMMAND_HPP

#include "Command.hpp"

class UsubCommand: public Command {
public:
    UsubCommand();
    UsubCommand(std::string login, std::string type, int threadId);
    UsubCommand(const UsubCommand& orig);
    virtual ~UsubCommand();

    static PCommand create(const std::vector<std::string>& strs);
private:
    std::string _login;
    std::string _type;
    int _threadId;
};

#endif	/* USUBCOMMAND_HPP */


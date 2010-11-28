/* 
 * File:   AuthCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:16
 */

#ifndef AUTHCOMMAND_HPP
#define	AUTHCOMMAND_HPP

#include <iostream>
#include "Command.hpp"

class AuthCommand: public Command {
public:
    AuthCommand();
    AuthCommand(std::string login, std::string password, int threadId);
    AuthCommand(const AuthCommand& orig);
    virtual ~AuthCommand();
    
    static PCommand create(const std::vector<std::string>& strs);
private:
    std::string _login;
    std::string _password;
    int _threadId;
};

#endif	/* AUTHCOMMAND_HPP */


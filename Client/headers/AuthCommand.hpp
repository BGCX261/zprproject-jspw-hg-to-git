/* 
 * File:   AuthCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:16
 */

#ifndef AUTHCOMMAND_HPP
#define	AUTHCOMMAND_HPP

#include "Command.hpp"
#include "CommandThread.hpp"

class AuthCommand: public Command, public CommandThread {
public:
    AuthCommand(std::string login, std::string password, int threadId);
    AuthCommand(const AuthCommand& orig);
    virtual ~AuthCommand();
    
    static PCommand create(const std::vector<std::string>& strs);
    virtual void accept(const Visitor& visitor) const;

    std::string getLogin() const;
    std::string getPasswd() const;
    
private:
    std::string _login;
    std::string _password;
};

#endif	/* AUTHCOMMAND_HPP */


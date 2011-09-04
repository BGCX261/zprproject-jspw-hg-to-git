/* 
 * File:   AuthCommand.cpp
 * Author: Pawel
 *
 * Implementacja klasy AuthCommand
 * Created on 26 listopad 2010, 14:16
 */

#include "AuthCommand.hpp"
#include "Visitor.hpp"
#include "ExceptionClient.hpp"
#include <boost/lexical_cast.hpp>

namespace Client
{
    AuthCommand::AuthCommand(std::string login, std::string password, int threadId) :
        CommandThread(threadId), _login(login), _password(password) {
    }

    AuthCommand::AuthCommand(const AuthCommand& orig) :
        CommandThread(orig), _login(orig._login), _password(orig._password) {
    }

    AuthCommand::~AuthCommand() {
    }

    AuthCommand::PCommand AuthCommand::create(const std::vector<std::string>& strs) {
        if (strs.size() != 3)
            throw ExceptionClient("AuthCommand create: wrong number of parameters, expected 3.");
        return PCommand(new AuthCommand(strs[1], strs[2], boost::lexical_cast<int>(strs[0])));
    }

    void AuthCommand::accept(Visitor& visitor) const {
        visitor.handle(*this);
    }

    std::string AuthCommand::getLogin() const {
        return _login;
    }

    std::string AuthCommand::getPasswd() const {
        return _password;
    }
}
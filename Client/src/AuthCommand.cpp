/* 
 * File:   AuthCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:16
 */

#include "AuthCommand.hpp"
#include <boost/lexical_cast.hpp>

AuthCommand::AuthCommand() {

}

AuthCommand::AuthCommand(std::string login, std::string password, int threadId) :
    _login(login), _password(password), _threadId(threadId) {
    
}

AuthCommand::AuthCommand(const AuthCommand& orig) {
}

AuthCommand::~AuthCommand() {
}

AuthCommand::PCommand AuthCommand::create(const std::vector<std::string>& strs) {
    if (strs.size() != 3)
        throw new std::exception();
    return PCommand(new AuthCommand(strs[1], strs[2], boost::lexical_cast<int>(strs[0])));
}


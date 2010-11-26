/* 
 * File:   AuthCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:16
 */

#include "AuthCommand.hpp"

AuthCommand::AuthCommand() {
}

AuthCommand::AuthCommand(const AuthCommand& orig) {
}

AuthCommand::~AuthCommand() {
}

Command* AuthCommand::create() {
    std::cout << "lala" << std::endl;
    return new AuthCommand;
}


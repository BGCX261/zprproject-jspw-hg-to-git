/* 
 * File:   SubsCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:16
 */

#include "Visitor.hpp"


#include "SubsCommand.hpp"
#include <boost/lexical_cast.hpp>

SubsCommand::SubsCommand(std::string login, std::string type, int threadId) :
    CommandThread(threadId), _login(login), _type(type) {
    
}

SubsCommand::SubsCommand(const SubsCommand& orig) :
    CommandThread(orig), _login(orig._login), _type(orig._type) {
}

SubsCommand::~SubsCommand() {
}

SubsCommand::PCommand SubsCommand::create(const std::vector<std::string>& strs) {
    if (strs.size() != 3)
        throw new std::exception();
    return PCommand(new SubsCommand(strs[1], strs[2], boost::lexical_cast<int>(strs[0])));
}

void SubsCommand::accept(const Visitor& visitor) const {
    visitor.handle(*this);
}

std::string SubsCommand::getLogin() const {
    return _login;
}

std::string SubsCommand::getType() const {
    return _type;
}
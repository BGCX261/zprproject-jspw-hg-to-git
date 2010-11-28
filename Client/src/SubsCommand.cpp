/* 
 * File:   SubsCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:16
 */

#include "SubsCommand.hpp"
#include <boost/lexical_cast.hpp>

SubsCommand::SubsCommand() {
}

SubsCommand::SubsCommand(std::string login, std::string type, int threadId) :
    _login(login), _type(type), _threadId(threadId) {
    
}

SubsCommand::SubsCommand(const SubsCommand& orig) {
}

SubsCommand::~SubsCommand() {
}

SubsCommand::PCommand SubsCommand::create(const std::vector<std::string>& strs) {
    if (strs.size() != 3)
        throw new std::exception();
    return PCommand(new SubsCommand(strs[1], strs[2], boost::lexical_cast<int>(strs[0])));
}
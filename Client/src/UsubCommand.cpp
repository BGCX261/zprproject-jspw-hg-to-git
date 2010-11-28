/* 
 * File:   UsubCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:19
 */

#include "UsubCommand.hpp"
#include <boost/lexical_cast.hpp>

UsubCommand::UsubCommand() {
}

UsubCommand::UsubCommand(std::string login, std::string type, int threadId) :
    _login(login), _type(type), _threadId(threadId) {
    
}

UsubCommand::UsubCommand(const UsubCommand& orig) {
}

UsubCommand::~UsubCommand() {
}

UsubCommand::PCommand UsubCommand::create(const std::vector<std::string>& strs) {
    if (strs.size() != 3)
        throw new std::exception();
    return PCommand(new UsubCommand(strs[1], strs[2], boost::lexical_cast<int>(strs[0])));
}
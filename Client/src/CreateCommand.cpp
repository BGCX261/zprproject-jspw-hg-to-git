/* 
 * File:   CreateCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:21
 */

#include "CreateCommand.hpp"
#include <boost/lexical_cast.hpp>

CreateCommand::CreateCommand() {
}

CreateCommand::CreateCommand(int threadId) :
    _threadId(threadId) {
    
}

CreateCommand::CreateCommand(const CreateCommand& orig) {
}

CreateCommand::~CreateCommand() {
}

CreateCommand::PCommand CreateCommand::create(const std::vector<std::string>& strs) {
    if (strs.size() != 1)
        throw new std::exception();
    return PCommand(new CreateCommand(boost::lexical_cast<int>(strs[0])));
}
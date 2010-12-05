/* 
 * File:   DiscCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:20
 */

#include "DiscCommand.hpp"
#include "Visitor.hpp"
#include <boost/lexical_cast.hpp>

DiscCommand::DiscCommand(int threadId) :
    CommandThread(threadId) {
}

DiscCommand::DiscCommand(const DiscCommand& orig) :
    CommandThread(orig){
}

DiscCommand::~DiscCommand() {
}

DiscCommand::PCommand DiscCommand::create(const std::vector<std::string>& strs) {
    if (strs.size() != 1)
        throw new std::exception();
    return PCommand(new DiscCommand(boost::lexical_cast<int>(strs[0])));
}

void DiscCommand::accept(const Visitor& visitor) const {
    visitor.handle(*this);
}
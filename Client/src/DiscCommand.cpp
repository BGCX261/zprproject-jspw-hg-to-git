/* 
 * File:   DiscCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:20
 */

#include "DiscCommand.hpp"

DiscCommand::DiscCommand() {
}

DiscCommand::DiscCommand(const DiscCommand& orig) {
}

DiscCommand::~DiscCommand() {
}

Command* DiscCommand::create() {
    return new DiscCommand;
}

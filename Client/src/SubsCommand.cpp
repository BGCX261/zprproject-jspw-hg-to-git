/* 
 * File:   SubsCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:16
 */

#include "SubsCommand.hpp"

SubsCommand::SubsCommand() {
}

SubsCommand::SubsCommand(const SubsCommand& orig) {
}

SubsCommand::~SubsCommand() {
}

Command* SubsCommand::create() {
    return new SubsCommand;
}
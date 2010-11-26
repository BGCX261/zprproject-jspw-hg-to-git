/* 
 * File:   CreateCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:21
 */

#include "CreateCommand.hpp"

CreateCommand::CreateCommand() {
}

CreateCommand::CreateCommand(const CreateCommand& orig) {
}

CreateCommand::~CreateCommand() {
}

Command* CreateCommand::create() {
    return new CreateCommand;
}
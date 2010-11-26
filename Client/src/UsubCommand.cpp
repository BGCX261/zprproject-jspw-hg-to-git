/* 
 * File:   UsubCommand.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 14:19
 */

#include "UsubCommand.hpp"

UsubCommand::UsubCommand() {
}

UsubCommand::UsubCommand(const UsubCommand& orig) {
}

UsubCommand::~UsubCommand() {
}

Command* UsubCommand::create() {
    return new UsubCommand;
}
/* 
 * File:   Configuration.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 22:42
 */

#include "Configuration.hpp"
#include "Interpreter.hpp"
#include "CreateCommand.hpp"
#include "AuthCommand.hpp"
#include "DiscCommand.hpp"
#include "SubsCommand.hpp"
#include "UsubCommand.hpp"

void Configuration::config() {
    registerCmd();
}

void Configuration::registerCmd() {
    Interpreter::PInterpreter interpreter = Interpreter::getInstance();
    interpreter->registerCmd("create", CreateCommand::create);
    interpreter->registerCmd("auth", AuthCommand::create);
    interpreter->registerCmd("disconnect", DiscCommand::create);
    interpreter->registerCmd("subs", SubsCommand::create);
    interpreter->registerCmd("unsub", UsubCommand::create);
}


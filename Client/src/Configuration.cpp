/* 
 * File:   Configuration.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 22:42
 */

#include "Configuration.hpp"
#include "CmdFactory.hpp"
#include "CreateCommand.hpp"
#include "AuthCommand.hpp"
#include "DiscCommand.hpp"
#include "SubsCommand.hpp"
#include "UsubCommand.hpp"

void Configuration::config() {
    registerCmds();
}

void Configuration::registerCmds() {
    CmdFactory::PCmdFactory cmdFactory = CmdFactory::getInstance();
    cmdFactory->registerCmd("create", CreateCommand::create);
    cmdFactory->registerCmd("auth", AuthCommand::create);
    cmdFactory->registerCmd("disconnect", DiscCommand::create);
    cmdFactory->registerCmd("subs", SubsCommand::create);
    cmdFactory->registerCmd("unsub", UsubCommand::create);
}


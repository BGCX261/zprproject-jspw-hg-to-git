/* 
 * File:   Configuration.cpp
 * Author: Pawel
 *
 * Implementacja klasy Configuration
 * Created on 26 listopad 2010, 22:42
 */

#include "Configuration.hpp"
#include "CmdFactory.hpp"
#include "CreateCommand.hpp"
#include "AuthCommand.hpp"
#include "DiscCommand.hpp"
#include "SubsCommand.hpp"
#include "UsubCommand.hpp"
#include "NewMsgCommand.hpp"

namespace Client
{
    std::string Configuration::_ip;
    std::string Configuration::_port;

    void Configuration::config(std::string ip, std::string port) {
        registerCmds();
        _ip = ip;
        _port = port;
    }

    void Configuration::registerCmds() {
        CmdFactory::PCmdFactory cmdFactory = CmdFactory::getInstance();
        cmdFactory->registerCmd("create", CreateCommand::create);
        cmdFactory->registerCmd("auth", AuthCommand::create);
        cmdFactory->registerCmd("disconnect", DiscCommand::create);
        cmdFactory->registerCmd("subs", SubsCommand::create);
        cmdFactory->registerCmd("unsub", UsubCommand::create);
        cmdFactory->registerCmd("newmsg", NewMsgCommand::create);
    }

    std::string Configuration::getIp() {
        return _ip;
    }

    std::string Configuration::getPort() {
        return _port;
    }
}


/* 
 * File:   Interpreter.cpp
 * Author: Pawel
 * 
 * Created on 30 listopad 2010, 15:50
 */

#include "Interpreter.hpp"
#include "Pool.hpp"

Interpreter::PInterpreter Interpreter::_pInstance;

Interpreter::Interpreter() {
}

Interpreter::~Interpreter() {
}

Interpreter::PInterpreter Interpreter::getInstance() {
    if(_pInstance.get() == NULL)
        _pInstance = PInterpreter(new Interpreter);
    return _pInstance;
}

void Interpreter::handle(const AuthCommand& authCmd) const {
    Pool::getInstance()->passCmd(authCmd.getId(), authCmd);
}

void Interpreter::handle(const CreateCommand& createCmd) const {
    Pool::getInstance()->createThread(createCmd.getId());
}

void Interpreter::handle(const DiscCommand& discCmd) const {
    Pool::getInstance()->passCmd(discCmd.getId(), discCmd);
}

void Interpreter::handle(const SubsCommand& subsCmd) const {
    Pool::getInstance()->passCmd(subsCmd.getId(), subsCmd);
}

void Interpreter::handle(const UsubCommand& usubCmd) const {
    Pool::getInstance()->passCmd(usubCmd.getId(), usubCmd);
}

void Interpreter::interpret(const Command& cmd) {
    cmd.accept(*this);
}


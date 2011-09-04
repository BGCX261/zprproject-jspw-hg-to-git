/* 
 * File:   Interpreter.cpp
 * Author: Pawel
 *
 * Implementacja klasy Interpreter
 * Created on 30 listopad 2010, 15:50
 */

#include "Interpreter.hpp"
#include "Pool.hpp"

namespace Client
{
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

    void Interpreter::handle(const AuthCommand& authCmd){
        Pool::getInstance()->passCmd(authCmd.getId(), authCmd);
    }

    void Interpreter::handle(const CreateCommand& createCmd){
        Pool::getInstance()->createThread(createCmd.getId());
    }

    void Interpreter::handle(const DiscCommand& discCmd){
        Pool::getInstance()->passCmd(discCmd.getId(), discCmd);
    }

    void Interpreter::handle(const SubsCommand& subsCmd){
        Pool::getInstance()->passCmd(subsCmd.getId(), subsCmd);
    }

    void Interpreter::handle(const UsubCommand& usubCmd){
        Pool::getInstance()->passCmd(usubCmd.getId(), usubCmd);
    }

    void Interpreter::handle(const NewMsgCommand& newCmd) {
        Pool::getInstance()->passCmd(newCmd.getId(), newCmd);
    }

    void Interpreter::interpret(const Command& cmd) {
        cmd.accept(*this);
    }
}


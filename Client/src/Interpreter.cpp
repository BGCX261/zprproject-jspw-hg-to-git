/* 
 * File:   Interpreter.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 20:41
 */

#include "Interpreter.hpp"

Interpreter::PInterpreter Interpreter::_pInstance;

Interpreter::Interpreter() {
}

Interpreter::Interpreter(const Interpreter& orig) {
}

Interpreter::PInterpreter Interpreter::getInstance() {
    if(_pInstance.get() == NULL)
        _pInstance = PInterpreter(new Interpreter);
    return _pInstance;
}

Command* Interpreter::create(const std::string& key) {
    Callbacks::const_iterator i = _callbacks.find(key);
    if(i == _callbacks.end())
        //throw new exception
        return NULL;
    else
        return (i->second)();
}

bool Interpreter::registerCmd(const std::string& key, NewCmdFun fun) {
    _callbacks.insert(std::make_pair(key, fun));
}
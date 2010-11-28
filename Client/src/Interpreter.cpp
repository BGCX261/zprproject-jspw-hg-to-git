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

Interpreter::~Interpreter() {
    
}

Interpreter::PInterpreter Interpreter::getInstance() {
    if(_pInstance.get() == NULL)
        _pInstance = PInterpreter(new Interpreter);
    return _pInstance;
}

Command::PCommand Interpreter::create(const std::string& key, const std::vector<std::string>& strs) {
    return (find(key)->second)(strs);
}

Command::PCommand Interpreter::create(const std::vector<std::string>& strs) {
    std::vector<std::string> copy(strs);
    copy.erase(copy.begin());
    return (find(strs[0])->second)(strs);
}

bool Interpreter::registerCmd(const std::string& key, NewCmdFun fun) {
    _callbacks.insert(std::make_pair(key, fun));
}

Interpreter::Callbacks::const_iterator Interpreter::find(const std::string& key) {
    Callbacks::const_iterator i = _callbacks.find(key);
    if(i == _callbacks.end())
        throw new std::exception();
    else
        return i;
}
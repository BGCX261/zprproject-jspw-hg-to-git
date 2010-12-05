/* 
 * File:   CmdFactory.cpp
 * Author: Pawel
 * 
 * Created on 26 listopad 2010, 20:41
 */

#include "CmdFactory.hpp"
#include <iostream>
CmdFactory::PCmdFactory CmdFactory::_pInstance;

CmdFactory::CmdFactory() {
}

CmdFactory::CmdFactory(const CmdFactory& orig) {
}

CmdFactory::~CmdFactory() {
    
}

CmdFactory::PCmdFactory CmdFactory::getInstance() {
    if(_pInstance.get() == NULL)
        _pInstance = PCmdFactory(new CmdFactory);
    return _pInstance;
}

Command::PCommand CmdFactory::create(const std::string& key, const std::vector<std::string>& strs) {
    return (find(key)->second)(strs);
}

Command::PCommand CmdFactory::create(const std::vector<std::string>& strs) {
    std::vector<std::string> copy(strs);
    copy.erase(copy.begin());
    return (find(strs[0])->second)(copy);
}

bool CmdFactory::registerCmd(const std::string& key, NewCmdFun fun) {
    _callbacks.insert(std::make_pair(key, fun));
}

CmdFactory::Callbacks::const_iterator CmdFactory::find(const std::string& key) {
    Callbacks::const_iterator i = _callbacks.find(key);
    if(i == _callbacks.end())
        throw new std::exception();
    else
        return i;
}
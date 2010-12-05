/* 
 * File:   ConditionVariable.cpp
 * Author: Pawel
 * 
 * Created on 1 grudzień 2010, 16:41
 */

#include "ConditionVariable.hpp"

ConditionVariable::ConditionVariable() {
}

ConditionVariable::ConditionVariable(const ConditionVariable& orig) {
}

ConditionVariable::~ConditionVariable() {
}

void ConditionVariable::notify_one() {
    boost::mutex::scoped_lock lock(_mutex);
    _condVar.notify_one();
    //todo
}

void ConditionVariable::wait() {
    boost::mutex::scoped_lock lock(_mutex);
    _condVar.wait(lock);
    //todo
}
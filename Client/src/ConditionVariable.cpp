/* 
 * File:   ConditionVariable.cpp
 * Author: Pawel
 *
 * Implementacja klasy ConditionVariable
 * Created on 1 grudzień 2010, 16:41
 */

#include "ConditionVariable.hpp"

namespace Client
{
    ConditionVariable::ConditionVariable() {
    }

    ConditionVariable::~ConditionVariable() {
        _mutex.unlock();
    }

    void ConditionVariable::notify_one() {
        boost::mutex::scoped_lock lock(_mutex);
        _condVar.notify_one();
    }

    void ConditionVariable::wait() {
        boost::mutex::scoped_lock lock(_mutex);
        _condVar.wait(lock);
    }
}
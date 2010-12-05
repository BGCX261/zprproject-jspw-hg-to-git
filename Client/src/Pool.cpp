/* 
 * File:   Pool.cpp
 * Author: Pawel
 * 
 * Created on 27 listopad 2010, 21:13
 */

#include "Pool.hpp"
#include "Terminal.hpp"
#include "Exception.hpp"

Pool::PPool Pool::_pInstance;

Pool::Pool() {
}

Pool::~Pool() {
}

Pool::PPool Pool::getInstance() {
    if(_pInstance.get() == NULL)
        _pInstance = PPool(new Pool);
    return _pInstance;
}

void Pool::createThread(int id){
    //if id exists exception
    if (_threads.count(id) != 0)
        throw Exception();
    Thread::PThread pThread(new Thread(id));
    _threads.insert(std::make_pair(id, pThread));
}

void Pool::passCmd(int threadId, const Command& cmd) {
    Thread::PThread pThread;
    pThread = _threads.find(threadId)->second;
    pThread->sendCmd(cmd);
}
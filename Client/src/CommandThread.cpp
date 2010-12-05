/* 
 * File:   CommandThread.cpp
 * Author: Pawel
 * 
 * Created on 30 listopad 2010, 16:00
 */

#include "CommandThread.hpp"
#include "Visitor.hpp"

CommandThread::CommandThread(int threadId) :
    _threadId(threadId) {
}

CommandThread::CommandThread(const CommandThread& orig) {
    this->_threadId = orig._threadId;
}

CommandThread::~CommandThread() {
}

int CommandThread::getId() const {
    return _threadId;
}


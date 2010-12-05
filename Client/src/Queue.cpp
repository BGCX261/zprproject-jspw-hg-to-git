/* 
 * File:   Queue.cpp
 * Author: Pawel
 * 
 * Created on 30 listopad 2010, 16:55
 */

#include "Queue.hpp"

Queue::Queue() {
    
}

Queue::Queue(ConditionVariable::PCondVar generalCondVar) :
    _generalCondVar(generalCondVar) {

}

Queue::~Queue() {
}

bool Queue::empty() const {
    boost::mutex::scoped_lock lock(_mutex);
    return _queue.empty();
}

void Queue::push(const Command& cmd) {
    boost::mutex::scoped_lock lock(_mutex);
    cmd.accept(*this);
    //_queue.push(cmd);
    lock.unlock();
    _generalCondVar->notify_one();
}

bool Queue::tryPop(Command::PCommand pCmd) {
    boost::mutex::scoped_lock lock(_mutex);
    if(_queue.empty()) {
        return false;
    }
    pCmd = _queue.front();
    _queue.pop();
    return true;
}

void Queue::setCondVar(ConditionVariable::PCondVar var) {
    _generalCondVar = var;
}

/*
void Queue::pop(Command& cmd) {
    boost::mutex::scoped_lock lock(_mutex);
    while(_queue.empty()) {
        _generalCondVar->wait(lock);
    }
    cmd = _queue.front();
    _queue.pop();
}
*/

void Queue::handle(const AuthCommand& cmd) const {
    Command::PCommand ap(new AuthCommand(cmd));
    _queue.push(ap);
}

void Queue::handle(const CreateCommand& cmd) const {
    Command::PCommand ap(new CreateCommand(cmd));
    _queue.push(ap);
}

void Queue::handle(const DiscCommand& cmd) const {
    Command::PCommand ap(new DiscCommand(cmd));
    _queue.push(ap);
}

void Queue::handle(const SubsCommand& cmd) const {
    Command::PCommand ap(new SubsCommand(cmd));
    _queue.push(ap);
}

void Queue::handle(const UsubCommand& cmd) const {
    Command::PCommand ap(new UsubCommand(cmd));
    _queue.push(ap);
}


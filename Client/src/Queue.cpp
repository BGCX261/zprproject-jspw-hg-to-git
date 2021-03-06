/* 
 * File:   Queue.cpp
 * Author: Pawel
 *
 * Implementacja klasy Queue
 * Created on 30 listopad 2010, 16:55
 */

#include "Queue.hpp"

namespace Client
{
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
        lock.unlock();
        _generalCondVar->notify_one();
    }

    bool Queue::tryPop(Command::PCommand& pCmd) {
        boost::mutex::scoped_lock lock(_mutex);
        if(_queue.empty()) {
            return false;
        }
        pCmd = _queue.front();
        _queue.pop();
        return true;
    }

    bool Queue::exists() const {
        boost::mutex::scoped_lock lock(_mutex);
        return _existing;
    }

    void Queue::setExists(bool exists) {
        boost::mutex::scoped_lock lock(_mutex);
        _existing = exists;
    }

    void Queue::setCondVar(ConditionVariable::PCondVar var) {
        _generalCondVar = var;
    }

    void Queue::handle(const AuthCommand& cmd) {
        Command::PCommand ap(new AuthCommand(cmd));
        _queue.push(ap);
    }

    void Queue::handle(const CreateCommand& cmd) {
        Command::PCommand ap(new CreateCommand(cmd));
        _queue.push(ap);
    }

    void Queue::handle(const DiscCommand& cmd) {
        Command::PCommand ap(new DiscCommand(cmd));
        _queue.push(ap);
    }

    void Queue::handle(const SubsCommand& cmd) {
        Command::PCommand ap(new SubsCommand(cmd));
        _queue.push(ap);
    }

    void Queue::handle(const UsubCommand& cmd) {
        Command::PCommand ap(new UsubCommand(cmd));
        _queue.push(ap);
    }

    void Queue::handle(const NewMsgCommand& cmd) {
        Command::PCommand ap(new NewMsgCommand(cmd));
        _queue.push(ap);
    }
}

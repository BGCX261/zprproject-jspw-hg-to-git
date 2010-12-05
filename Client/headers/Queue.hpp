/* 
 * File:   Queue.hpp
 * Author: Pawel
 *
 * Created on 30 listopad 2010, 16:55
 */

#ifndef QUEUE_HPP
#define	QUEUE_HPP

#include "Command.hpp"
#include "Visitor.hpp"
#include "ConditionVariable.hpp"
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/shared_ptr.hpp>
#include <queue>

class Queue: public Visitor {
public:
    Queue();
    Queue(ConditionVariable::PCondVar generalCondVar);
    virtual ~Queue();

    void push(const Command& cmd);
    bool empty() const;
    bool tryPop(Command::PCommand pCmd);
    void setCondVar(ConditionVariable::PCondVar var);
    //void pop(Command& cmd);

    virtual void handle(const AuthCommand& ) const;
    virtual void handle(const CreateCommand& ) const;
    virtual void handle(const DiscCommand& ) const;
    virtual void handle(const SubsCommand& ) const;
    virtual void handle(const UsubCommand& ) const;
    
private:

    mutable std::queue<Command::PCommand> _queue;
    mutable boost::mutex _mutex;
    //boost::condition_variable _condVar;
    ConditionVariable::PCondVar _generalCondVar;
};

#endif	/* QUEUE_HPP */


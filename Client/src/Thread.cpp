/* 
 * File:   Thread.cpp
 * Author: Pawel
 * 
 * Created on 27 listopad 2010, 21:26
 */

#include "Thread.hpp"
#include "Terminal.hpp"
#include <iostream>

Thread::Thread(int id) : 
    _id(id), _pBThread(new boost::thread(&Worker::run, &_worker))  {
}

Thread::~Thread() {
}

void Thread::run() {
    //_pBThread = PBThread(new boost::thread(&Worker::run, &_worker));
    //skasowac join
    _pBThread->join();
}

void Thread::sendCmd(const Command& cmd) {
    _worker.queue.push(cmd);
}

Thread::Worker::Worker() : 
    pCondVar(new ConditionVariable()), queue(pCondVar) {
}

Thread::Worker::~Worker() {

}

void Thread::Worker::run() {
    Terminal::getInstance()->write("Worker\n");\
    Command::PCommand pCmd;
    while(1) {
        pCondVar->wait();
        if (queue.tryPop(pCmd)) {
            Terminal::getInstance()->write("Command");
            pCmd->accept(*this);
        }
        //if tcp/ip
    }
}

void Thread::Worker::handle(const AuthCommand& authCmd) const {

}

void Thread::Worker::handle(const CreateCommand& createCmd) const {
    //exception
}

void Thread::Worker::handle(const DiscCommand& discCmd) const {

}

void Thread::Worker::handle(const SubsCommand& subsCmd) const {

}

void Thread::Worker::handle(const UsubCommand& usubCmd) const {
    
}
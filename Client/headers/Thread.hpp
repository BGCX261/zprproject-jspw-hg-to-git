/* 
 * File:   Thread.hpp
 * Author: Pawel
 *
 * Created on 27 listopad 2010, 21:26
 */

#ifndef THREAD_HPP
#define	THREAD_HPP

#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include "ConditionVariable.hpp"
#include "ClientVisitor.hpp"
#include "Queue.hpp"

using namespace SubscriptionLib;

class Thread {
public:
    typedef boost::shared_ptr<Thread> PThread;

    Thread(int id);
    virtual ~Thread();

    void run();
    void sendCmd(const Command& cmd);
private:
    typedef boost::shared_ptr<boost::thread> PBThread;

    struct Worker;

    int _id;
    Worker _worker;
    PBThread _pBThread;
};

struct Thread::Worker: public Visitor, public ClientVisitor {
    ConditionVariable::PCondVar pCondVar;
    Queue queue;
    Client client;

    Worker(/*parameters*/);
    ~Worker();

    void run();

    void handle(const AuthCommand& authCmd);
    void handle(const CreateCommand& createCmd);
    void handle(const DiscCommand& discCmd);
    void handle(const SubsCommand& subsCmd);
    void handle(const UsubCommand& usubCmd);

    virtual void handle(const AuthResponse& res);
    virtual void handle(const MsgResponse& res);
    virtual void handle(const NewMsgResponse& res);
    virtual void handle(const SubsResponse& res);
    virtual void handle(const UsubResponse& res);
};

#endif	/* THREAD_HPP */


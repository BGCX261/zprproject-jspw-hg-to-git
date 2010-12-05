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
#include "Queue.hpp"

class Thread {
public:
    typedef boost::shared_ptr<Thread> PThread;

    Thread(int id);
    virtual ~Thread();

    void run();
    void sendCmd(const Command& cmd);

private:
    typedef boost::shared_ptr<boost::thread> PBThread;

    struct Worker: public Visitor {
        ConditionVariable::PCondVar pCondVar;
        Queue queue;
        
        Worker(/*parameters*/);
        ~Worker();
        
        void run();

        void handle(const AuthCommand& authCmd) const;
        void handle(const CreateCommand& createCmd) const;
        void handle(const DiscCommand& discCmd) const;
        void handle(const SubsCommand& subsCmd) const;
        void handle(const UsubCommand& usubCmd) const;
    };

    int _id;
    Worker _worker;
    PBThread _pBThread;
};

#endif	/* THREAD_HPP */


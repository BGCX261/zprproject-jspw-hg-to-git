/* 
 * File:   Pool.hpp
 * Author: Pawel
 *
 * Created on 27 listopad 2010, 21:13
 */

#ifndef POOL_HPP
#define	POOL_HPP

#include "Thread.hpp"
#include "Command.hpp"
#include <boost/shared_ptr.hpp>
#include <map>

class Pool {
public:
    typedef boost::shared_ptr<Pool> PPool;

    static PPool getInstance();
    void createThread(int id);
    void passCmd(int threadId, const Command& cmd);

    virtual ~Pool();
    
private:
    typedef std::map<int, Thread::PThread> ThreadsSet;

    static PPool _pInstance;
    ThreadsSet _threads;

    Pool();
};

#endif	/* POOL_HPP */


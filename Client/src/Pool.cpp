/* 
 * File:   Pool.cpp
 * Author: Pawel
 *
 * Implementacja klasy Pool
 * Created on 27 listopad 2010, 21:13
 */

#include "Pool.hpp"
#include "Terminal.hpp"
#include "ExceptionClient.hpp"

namespace Client
{
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
        if (_threads.count(id) != 0)
            throw ExceptionClient(boost::format("Worker %1% already exists") % id);
        Thread::PThread pThread(new Thread(id));
        _threads.insert(std::make_pair(id, pThread));
    }

    void Pool::passCmd(int threadId, const Command& cmd) {
        Thread::PThread pThread;
        ThreadsSet::const_iterator it = _threads.find(threadId);
        if (it == _threads.end())
            throw ExceptionClient(boost::format("Worker with id %1% doesn't exist") % threadId);
        pThread = it->second;
        pThread->sendCmd(cmd);
    }
}
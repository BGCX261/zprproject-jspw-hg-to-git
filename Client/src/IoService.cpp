/* 
 * File:   IoService.cpp
 * Author: Pawel
 *
 * Implementacja klasy IoService
 * Created on 12 styczeń 2011, 19:49
 */

#include "IoService.hpp"
#include <iostream>

namespace Client
{
    IoService::PIoService IoService::_pInstance;

    IoService::IoService():
        _service(), _thread(boost::bind(&IoService::doRun, this)) {
    }

    IoService::~IoService() {
    }

    void IoService::run() {
        _cond.notify_one();
    }

    IoService::PIoService IoService::getInstance() {
        if(_pInstance.get() == NULL)
            _pInstance = PIoService(new IoService);
        return _pInstance;
    }

    boost::asio::io_service& IoService::getService() {
        return _service;
    }

    void IoService::doRun() {
        while(1) {
            _service.run();
            _service.reset();
            _cond.wait();
        }
    }
}


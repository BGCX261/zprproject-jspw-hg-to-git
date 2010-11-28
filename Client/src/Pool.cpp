/* 
 * File:   Pool.cpp
 * Author: Pawel
 * 
 * Created on 27 listopad 2010, 21:13
 */

#include "Pool.hpp"

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
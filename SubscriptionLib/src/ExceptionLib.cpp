/* 
 * File:   ExceptionLib.cpp
 * Author: Pawel
 *
 * Implementacja klasy ExceptionLib
 * Created on 7 styczeń 2011, 21:07
 */

#include "ExceptionLib.hpp"

namespace SubscriptionLib
{
    Exception::Exception() {
    }

    Exception::Exception(const std::string& str) :
        _str(str) {
    }

    Exception::Exception(const boost::format& format) :
        _str(boost::str(format)) {
    }

    Exception::~Exception() throw(){
    }
}


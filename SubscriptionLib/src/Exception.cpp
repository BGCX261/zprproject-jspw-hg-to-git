/* 
 * File:   Exception.cpp
 * Author: Pawel
 * 
 * Created on 7 styczeń 2011, 21:07
 */

#include "Exception.hpp"

Exception::Exception() {
}

Exception::Exception(const std::string& str) :
    _str(str) {
}


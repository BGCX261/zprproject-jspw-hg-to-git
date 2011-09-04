/* 
 * File:   ExceptionClient.cpp
 * Author: Pawel
 *
 * Implementacja klasy ExceptionClient
 * Created on 27 listopad 2010, 20:40
 */

#include <string>
#include <format/format_class.hpp>

#include "ExceptionClient.hpp"
#include "Terminal.hpp"

namespace Client
{
    ExceptionClient::ExceptionClient() {
    }

    ExceptionClient::ExceptionClient(const std::string& msg) :
        _message(msg) {
    }

    ExceptionClient::ExceptionClient(const ExceptionClient& orig) :
        _message(orig._message) {
    }

    ExceptionClient::ExceptionClient(const boost::format& format) :
        _message(format.str()) {
    }

    ExceptionClient::~ExceptionClient() throw() {
    }

    const char* ExceptionClient::what() const throw() {
        return _message.c_str();
    }
}

/* 
 * File:   Response.cpp
 * Author: Pawel
 *
 * Implementacja klasy Response
 * Created on 6 styczeń 2011, 23:57
 */

#include "Response.hpp"

namespace SubscriptionLib
{
    Response::Response() {
    }

    Response::Response(const int& status, const std::string& answer) :
        _status(status), _answer(answer) {
    }

    Response::Response(const Response& orig) :
        _status(orig._status), _answer(orig._answer) {
    }

    Response::~Response() {
    }

    bool Response::doSerialize(Archive& archive) const {
        archive << _status;
        archive << _answer;
    }

    bool Response::doDeserialize(Archive& archive) {
        archive >> _status;
        archive >> _answer;
    }

    int Response::getStatus() const {
        return _status;
    }

    std::string Response::getAnswer() const {
        return _answer;
    }
}

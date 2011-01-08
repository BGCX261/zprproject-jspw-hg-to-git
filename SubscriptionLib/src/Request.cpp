/* 
 * File:   Request.cpp
 * Author: Pawel
 * 
 * Created on 6 styczeń 2011, 23:57
 */

#include "Request.hpp"

namespace SubscriptionLib
{
    Request::Request() {
    }

    Request::Request(const std::string& login) :
        _login(login) {
    }

    Request::Request(const Request& orig) :
        _login(orig._login) {
    }

    bool Request::doSerialize(Archive& archive) const {
        archive << _login;
    }

    bool Request::doDeserialize(Archive& archive) {
        archive >> _login;
    }

    std::string Request::getLogin() const {
        return _login;
    }
}


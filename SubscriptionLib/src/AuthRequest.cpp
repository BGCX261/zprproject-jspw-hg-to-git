/* 
 * File:   AuthRequest.cpp
 * Author: Pawel
 * 
 * Created on 6 styczeń 2011, 23:58
 */

#include "AuthRequest.hpp"
#include "Id.hpp"

AuthRequest::AuthRequest() {
}

AuthRequest::AuthRequest(const std::string& login, const std::string& password) :
    Request(login), _password(password) {
    
}

AuthRequest::AuthRequest(const AuthRequest& orig) :
    Request(orig), _password(orig._password) {
}

std::string AuthRequest::id() const {
    return ClassId<AuthRequest>::id();
}

bool AuthRequest::doSerialize(Archive& archive) const {
    Request::doSerialize(archive);
    archive << _password;
}

bool AuthRequest::doDeserialize(Archive& archive) {
    Request::doDeserialize(archive);
    archive >> _password;
}

std::string AuthRequest::getPassword() const {
    return _password;
}

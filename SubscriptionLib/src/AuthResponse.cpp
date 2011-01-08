/* 
 * File:   AuthResponse.cpp
 * Author: Pawel
 * 
 * Created on 7 styczeń 2011, 00:02
 */

#include "AuthResponse.hpp"
#include "Id.hpp"

namespace SubscriptionLib
{
    AuthResponse::AuthResponse() {
    }

    AuthResponse::AuthResponse(const int& status, const std::string& answer) :
        Response(status, answer) {
    }

    AuthResponse::AuthResponse(const AuthResponse& orig) :
        Response(orig) {
    }

    void AuthResponse::accept(Visitor& visitor) const {
        visitor.handle(*this);
    }

    std::string AuthResponse::id() const {
        return ClassId<AuthResponse>::id();
    }

    bool AuthResponse::doSerialize(Archive& archive) const {
        Response::doSerialize(archive);
    }

    bool AuthResponse::doDeserialize(Archive& archive) {
        Response::doDeserialize(archive);
    }
}

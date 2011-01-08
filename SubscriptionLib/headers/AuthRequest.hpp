/* 
 * File:   AuthRequest.hpp
 * Author: Pawel
 *
 * Created on 6 styczeń 2011, 23:58
 */

#ifndef AUTHREQUEST_HPP
#define	AUTHREQUEST_HPP

#include "Request.hpp"

namespace SubscriptionLib
{
    class AuthRequest: public Request, public RegisterSerializeable<AuthRequest, Request> {
    public:
        AuthRequest();
        AuthRequest(const std::string& login, const std::string& password);
        AuthRequest(const AuthRequest& orig);
        std::string getPassword() const;
        virtual void accept(Visitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    private:
        std::string _password;
    };
}

#endif	/* AUTHREQUEST_HPP */


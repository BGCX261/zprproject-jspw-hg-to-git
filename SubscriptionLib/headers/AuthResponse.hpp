/* 
 * File:   AuthResponse.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 00:02
 */

#ifndef AUTHRESPONSE_HPP
#define	AUTHRESPONSE_HPP

#include "Response.hpp"
#include "Visitor.hpp"

namespace SubscriptionLib
{
    class AuthResponse: public Response, public RegisterSerializeable<AuthResponse, Response>  {
    public:
        AuthResponse();
        AuthResponse(const int& status, const std::string& answer);
        AuthResponse(const AuthResponse& orig);
        virtual void accept(Visitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    };
}

#endif	/* AUTHRESPONSE_HPP */


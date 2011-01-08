/* 
 * File:   NewMsgResponse.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 20:20
 */

#ifndef NEWMSGRESPONSE_HPP
#define	NEWMSGRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    class NewMsgResponse: public Response, public RegisterSerializeable<NewMsgResponse, Response> {
    public:
        NewMsgResponse();
        NewMsgResponse(const int& status, const std::string& answer);
        NewMsgResponse(const NewMsgResponse& orig);
        virtual void accept(Visitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);

    };
}

#endif	/* NEWMSGRESPONSE_HPP */


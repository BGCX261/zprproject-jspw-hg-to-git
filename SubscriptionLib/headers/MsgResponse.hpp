/* 
 * File:   MsgResponse.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 00:02
 */

#ifndef MSGRESPONSE_HPP
#define	MSGRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    class MsgResponse: public Response, public RegisterSerializeable<MsgResponse, Response> {
    public:
        MsgResponse();
        MsgResponse(const int& status, const std::string& answer, const std::string& info);
        MsgResponse(const MsgResponse& orig);
        std::string getInfo() const;
        virtual void accept(Visitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    private:
        std::string _info;
    };
}

#endif	/* MSGRESPONSE_HPP */


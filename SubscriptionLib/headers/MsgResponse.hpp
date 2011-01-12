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
        MsgResponse(const int& status, const std::string& answer, const std::string& subsId, const std::string& info);
        MsgResponse(const MsgResponse& orig);
        virtual ~MsgResponse();
        std::string getInfo() const;
        std::string getSubId() const;
        virtual void accept(ClientVisitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    private:
        std::string _info;
        std::string _subId;
    };
}

#endif	/* MSGRESPONSE_HPP */


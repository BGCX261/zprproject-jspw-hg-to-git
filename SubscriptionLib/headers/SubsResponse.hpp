/* 
 * File:   SubsResponse.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 00:02
 */

#ifndef SUBSRESPONSE_HPP
#define	SUBSRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    class SubsResponse: public Response, public RegisterSerializeable<SubsResponse, Response> {
    public:
        SubsResponse();
        SubsResponse(const int& status, const std::string& answer);
        SubsResponse(const SubsResponse& orig);
        virtual ~SubsResponse();
        virtual void accept(ClientVisitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    };
}

#endif	/* SUBSRESPONSE_HPP */


/* 
 * File:   UsubResponse.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 00:02
 */

#ifndef USUBRESPONSE_HPP
#define	USUBRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    class UsubResponse: public Response, public RegisterSerializeable<UsubResponse, Response> {
    public:
        UsubResponse();
        UsubResponse(const int& status, const std::string& answer);
        UsubResponse(const UsubResponse& orig);
        virtual ~UsubResponse();
        virtual void accept(ClientVisitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    };
}

#endif	/* USUBRESPONSE_HPP */


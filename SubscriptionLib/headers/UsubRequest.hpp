/* 
 * File:   UsubRequest.hpp
 * Author: Pawel
 *
 * Created on 6 styczeń 2011, 23:58
 */

#ifndef USUBREQUEST_HPP
#define	USUBREQUEST_HPP

#include "Request.hpp"

namespace SubscriptionLib
{
    class UsubRequest: public Request, public RegisterSerializeable<UsubRequest, Request> {
    public:
        UsubRequest();
        UsubRequest(const std::string& login, const std::string& subId);
        UsubRequest(const UsubRequest& orig);
        virtual ~UsubRequest();
        virtual void accept(ServerVisitor& visitor) const;
        std::string getSubId() const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    private:
        std::string _subId;
    };
}

#endif	/* USUBREQUEST_HPP */


/* 
 * File:   SubsRequest.hpp
 * Author: Pawel
 *
 * Created on 6 styczeń 2011, 23:58
 */

#ifndef SUBSREQUEST_HPP
#define	SUBSREQUEST_HPP

#include "Request.hpp"

namespace SubscriptionLib
{
    class SubsRequest: public Request, public RegisterSerializeable<SubsRequest, Request> {
    public:
        SubsRequest();
        SubsRequest(const std::string& login, const std::string& subId);
        SubsRequest(const SubsRequest& orig);
        virtual ~SubsRequest();
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

#endif	/* SUBSREQUEST_HPP */


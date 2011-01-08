/* 
 * File:   SubsRequest.cpp
 * Author: Pawel
 * 
 * Created on 6 styczeń 2011, 23:58
 */

#include "SubsRequest.hpp"
#include "Id.hpp"

namespace SubscriptionLib
{
    SubsRequest::SubsRequest() {
    }

    SubsRequest::SubsRequest(const std::string& login, const std::string& subId) :
        Request(login), _subId(subId) {
    }

    SubsRequest::SubsRequest(const SubsRequest& orig) :
        Request(orig), _subId(orig._subId) {
    }

    void SubsRequest::accept(Visitor& visitor) const {
        visitor.handle(*this);
    }

    std::string SubsRequest::id() const {
        return ClassId<SubsRequest>::id();
    }

    bool SubsRequest::doSerialize(Archive& archive) const {
        Request::doSerialize(archive);
        archive << _subId;
    }

    bool SubsRequest::doDeserialize(Archive& archive) {
        Request::doDeserialize(archive);
        archive >> _subId;
    }
}


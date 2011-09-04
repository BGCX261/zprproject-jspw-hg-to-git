/* 
 * File:   UsubRequest.cpp
 * Author: Pawel
 *
 * Implementacja klasy UsubRequest
 * Created on 6 styczeń 2011, 23:58
 */

#include "UsubRequest.hpp"
#include "Id.hpp"

namespace SubscriptionLib
{
    UsubRequest::UsubRequest() {
    }

    UsubRequest::UsubRequest(const std::string& login, const std::string& subId) :
        Request(login), _subId(subId) {
    }

    UsubRequest::UsubRequest(const UsubRequest& orig) :
        Request(orig), _subId(orig._subId) {
    }

    UsubRequest::~UsubRequest() {
    }

    void UsubRequest::accept(ServerVisitor& visitor) const {
        visitor.handle(*this);
    }

    std::string UsubRequest::id() const {
        return ClassId<UsubRequest>::id();
    }

    bool UsubRequest::doSerialize(Archive& archive) const {
        Request::doSerialize(archive);
        archive << _subId;
    }

    bool UsubRequest::doDeserialize(Archive& archive) {
        Request::doDeserialize(archive);
        archive >> _subId;
    }

    std::string UsubRequest::getSubId() const {
        return _subId;
    }
}

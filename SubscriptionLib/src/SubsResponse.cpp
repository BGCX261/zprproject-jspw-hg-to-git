/* 
 * File:   SubsResponse.cpp
 * Author: Pawel
 * 
 * Created on 7 styczeń 2011, 00:02
 */

#include "SubsResponse.hpp"
#include "Id.hpp"

namespace SubscriptionLib
{
    SubsResponse::SubsResponse() {
    }

    SubsResponse::SubsResponse(const int& status, const std::string& answer) :
        Response(status, answer) {
    }

    SubsResponse::SubsResponse(const SubsResponse& orig) :
        Response(orig) {
    }

    void SubsResponse::accept(Visitor& visitor) const {
        visitor.handle(*this);
    }

    std::string SubsResponse::id() const {
        return ClassId<SubsResponse>::id();
    }

    bool SubsResponse::doSerialize(Archive& archive) const {
        Response::doSerialize(archive);
    }

    bool SubsResponse::doDeserialize(Archive& archive) {
        Response::doDeserialize(archive);
    }
}


/* 
 * File:   MsgResponse.cpp
 * Author: Pawel
 * 
 * Created on 7 styczeń 2011, 00:02
 */

#include "MsgResponse.hpp"
#include "Id.hpp"

namespace SubscriptionLib
{
    MsgResponse::MsgResponse() {
    }

    MsgResponse::MsgResponse(const int& status, const std::string& answer, const std::string& info) :
        Response(status, answer), _info(info) {
    }

    MsgResponse::MsgResponse(const MsgResponse& orig) :
        Response(orig), _info(orig._info) {
    }

    void MsgResponse::accept(Visitor& visitor) const {
        visitor.handle(*this);
    }

    std::string MsgResponse::id() const {
        return ClassId<MsgResponse>::id();
    }

    bool MsgResponse::doSerialize(Archive& archive) const {
        Response::doSerialize(archive);
        archive << _info;
    }

    bool MsgResponse::doDeserialize(Archive& archive) {
        Response::doDeserialize(archive);
        archive >> _info;
    }
}
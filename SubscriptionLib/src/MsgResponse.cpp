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

    MsgResponse::MsgResponse(const int& status, const std::string& answer,
            const std::string& subId, const std::string& info) :
        Response(status, answer), _subId(subId), _info(info) {
    }

    MsgResponse::MsgResponse(const MsgResponse& orig) :
        Response(orig),_subId(orig._subId), _info(orig._info) {
    }

    MsgResponse::~MsgResponse() {
    }

    void MsgResponse::accept(ClientVisitor& visitor) const {
        visitor.handle(*this);
    }

    std::string MsgResponse::id() const {
        return ClassId<MsgResponse>::id();
    }

    bool MsgResponse::doSerialize(Archive& archive) const {
        Response::doSerialize(archive);
        archive << _subId;
        archive << _info;
    }

    bool MsgResponse::doDeserialize(Archive& archive) {
        Response::doDeserialize(archive);
        archive >> _subId;
        archive >> _info;
    }

    std::string MsgResponse::getInfo() const {
        return _info;
    }

    std::string MsgResponse::getSubId() const {
        return _subId;
    }
}
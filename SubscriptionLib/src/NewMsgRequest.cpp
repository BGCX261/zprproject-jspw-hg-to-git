/* 
 * File:   NewMsgRequestr.cpp
 * Author: Pawel
 *
 * Implementacja klasy NewMsgRequest
 * Created on 6 styczeń 2011, 23:59
 */

#include "NewMsgRequest.hpp"
#include "Id.hpp"

namespace SubscriptionLib
{
    NewMsgRequest::NewMsgRequest() {
    }

    NewMsgRequest::NewMsgRequest(const std::string& login, const std::string& subId, const std::string& info) :
        Request(login), _subId(subId), _info(info) {
    }

    NewMsgRequest::NewMsgRequest(const NewMsgRequest& orig) :
        Request(orig), _subId(orig._subId), _info(orig._info) {
    }

    NewMsgRequest::~NewMsgRequest() {
    }

    void NewMsgRequest::accept(ServerVisitor& visitor) const {
        visitor.handle(*this);
    }

    std::string NewMsgRequest::id() const {
        return ClassId<NewMsgRequest>::id();
    }

    bool NewMsgRequest::doSerialize(Archive& archive) const {
        Request::doSerialize(archive);
        archive << _subId;
        archive << _info;
    }

    bool NewMsgRequest::doDeserialize(Archive& archive) {
        Request::doDeserialize(archive);
        archive >> _subId;
        archive >> _info;
    }

    std::string NewMsgRequest::getSubId() const {
        return _subId;
    }

    std::string NewMsgRequest::getInfo() const {
        return _info;
    }
}


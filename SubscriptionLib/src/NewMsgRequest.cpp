/* 
 * File:   NewMsgRequestr.cpp
 * Author: Pawel
 * 
 * Created on 6 styczeń 2011, 23:59
 */

#include "NewMsgRequest.hpp"
#include "Id.hpp"

NewMsgRequest::NewMsgRequest() {
}

NewMsgRequest::NewMsgRequest(const std::string& login, const std::string& info) :
    Request(login), _info(info) {
}

NewMsgRequest::NewMsgRequest(const NewMsgRequest& orig) :
    Request(orig), _info(orig._info) {
}

std::string NewMsgRequest::id() const {
    return ClassId<NewMsgRequest>::id();
}

bool NewMsgRequest::doSerialize(Archive& archive) const {
    Request::doSerialize(archive);
    archive << _info;
}

bool NewMsgRequest::doDeserialize(Archive& archive) {
    Request::doDeserialize(archive);
    archive >> _info;
}


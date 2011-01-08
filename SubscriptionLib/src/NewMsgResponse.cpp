/* 
 * File:   NewMsgResponse.cpp
 * Author: Pawel
 * 
 * Created on 7 styczeń 2011, 20:20
 */

#include "NewMsgResponse.hpp"
#include "Id.hpp"

NewMsgResponse::NewMsgResponse() {
}

NewMsgResponse::NewMsgResponse(const int& status, const std::string& answer) :
    Response(status, answer) {

}

NewMsgResponse::NewMsgResponse(const NewMsgResponse& orig) :
    Response(orig) {
}

std::string NewMsgResponse::id() const {
    return ClassId<NewMsgResponse>::id();
}

bool NewMsgResponse::doSerialize(Archive& archive) const {
    Response::doSerialize(archive);
}

bool NewMsgResponse::doDeserialize(Archive& archive) {
    Response::doDeserialize(archive);
}


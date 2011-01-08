/* 
 * File:   UsubResponse.cpp
 * Author: Pawel
 * 
 * Created on 7 styczeń 2011, 00:02
 */

#include "UsubResponse.hpp"
#include "Id.hpp"

UsubResponse::UsubResponse() {
}

UsubResponse::UsubResponse(const int& status, const std::string& answer) :
    Response(status, answer) {
}

UsubResponse::UsubResponse(const UsubResponse& orig) :
    Response(orig) {
}

std::string UsubResponse::id() const {
    return ClassId<UsubResponse>::id();
}

bool UsubResponse::doSerialize(Archive& archive) const {
    Response::doSerialize(archive);
}

bool UsubResponse::doDeserialize(Archive& archive) {
    Response::doDeserialize(archive);
}
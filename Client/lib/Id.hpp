/* 
 * File:   Id.hpp
 * Author: Pawel
 *
 * Okreslenie id klas wiadomosci
 * Created on 7 styczeń 2011, 20:04
 */

#ifndef ID_HPP
#define	ID_HPP

#include "Serializeable.hpp"

#define ASSIGN_ID(_classname_, _id_)      \
class _classname_;                        \
template<> struct ClassId<_classname_>    \
{                                         \
    static std::string id() {             \
        return _id_;                      \
    }                                     \
};                                        \

namespace SubscriptionLib
{
    ASSIGN_ID(AuthRequest, "AUTH");
    ASSIGN_ID(SubsRequest, "SUBS");
    ASSIGN_ID(UsubRequest, "USUB");
    ASSIGN_ID(NewMsgRequest, "NMSG");
    ASSIGN_ID(AuthResponse, "ATHR");
    ASSIGN_ID(MsgResponse, "MSGR");
    ASSIGN_ID(SubsResponse, "SUBR");
    ASSIGN_ID(UsubResponse, "USBR");
    ASSIGN_ID(NewMsgResponse, "NMSR");
}

#endif	/* ID_HPP */


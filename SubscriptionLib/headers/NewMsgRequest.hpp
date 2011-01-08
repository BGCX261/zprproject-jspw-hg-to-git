/* 
 * File:   NewMsgRequest.hpp
 * Author: Pawel
 *
 * Created on 6 styczeń 2011, 23:59
 */

#ifndef NEWMSGREQUEST_HPP
#define	NEWMSGREQUEST_HPP

#include "Request.hpp"

namespace SubscriptionLib
{
    class NewMsgRequest: public Request, public RegisterSerializeable<NewMsgRequest, Request> {
    public:
        NewMsgRequest();
        NewMsgRequest(const std::string& login, const std::string& info);
        NewMsgRequest(const NewMsgRequest& orig);
        virtual void accept(Visitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    private:
        std::string _info;
    };
}

#endif	/* NEWMSGREQUEST_HPP */

/* 
 * File:   Response.hpp
 * Author: Pawel
 *
 * Created on 6 styczeń 2011, 23:57
 */

#ifndef RESPONSE_HPP
#define	RESPONSE_HPP

#include "Message.hpp"
#include "Serializeable.hpp"
#include "ClientVisitor.hpp"

namespace SubscriptionLib
{
    class Response: public Message, public Serializeable<Response> {
    public:
        typedef boost::shared_ptr<Response> PResponse;

        virtual ~Response();

        virtual void accept(ClientVisitor& visitor) const = 0;
        int getStatus() const;
        std::string getAnswer() const;
    protected:
        Response();
        Response(const int& status, const std::string& answer);
        Response(const Response& orig);

        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);

        int _status;
        std::string _answer;
    };
}

#endif	/* RESPONSE_HPP */


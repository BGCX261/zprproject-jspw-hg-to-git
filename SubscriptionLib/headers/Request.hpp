/* 
 * File:   Request.hpp
 * Author: Pawel
 *
 * Created on 6 styczeń 2011, 23:57
 */

#ifndef REQUEST_HPP
#define	REQUEST_HPP

#include "Message.hpp"
#include "Serializeable.hpp"

class Request: public Message, public Serializeable<Request> {
public:
    std::string getLogin() const;
protected:
    Request();
    Request(const std::string& login);
    Request(const Request& orig);

    virtual bool doSerialize(Archive& archive) const;
    virtual bool doDeserialize(Archive& archive);

    std::string _login;
};

#endif	/* REQUEST_HPP */


/* 
 * File:   Request.hpp
 * Author: Pawel
 *
 * Deklaracja klasy Request
 * Created on 6 styczeń 2011, 23:57
 */

#ifndef REQUEST_HPP
#define	REQUEST_HPP

#include "Message.hpp"
#include "ServerVisitor.hpp"
#include "Serializeable.hpp"

namespace SubscriptionLib
{
    /*
     * Klsa bazowa dla zadan
     */
    class Request: public Message, public Serializeable<Request> {
    public:
        typedef boost::shared_ptr<Request> PRequest;
        /*
         * Destruktor
         */
        virtual ~Request();
        /*
         * Akcpetacja wizytatora serwera
         * @param visitor Wizytator
         */
        virtual void accept(ServerVisitor& visitor) const = 0;
        /*
         * Pobranie loginu
         * @return Login
         */
        std::string getLogin() const;
    protected:
        Request();
        Request(const std::string& login);
        Request(const Request& orig);

        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);

        std::string _login;
    };
}

#endif	/* REQUEST_HPP */


/* 
 * File:   Response.hpp
 * Author: Pawel
 *
 * Deklaracja klasy Response
 * Created on 6 styczeń 2011, 23:57
 */

#ifndef RESPONSE_HPP
#define	RESPONSE_HPP

#include "Message.hpp"
#include "Serializeable.hpp"
#include "ClientVisitor.hpp"

namespace SubscriptionLib
{
    /*
     * Klasa bazowa dla odpowiedzi na zadania
     */
    class Response: public Message, public Serializeable<Response> {
    public:
        typedef boost::shared_ptr<Response> PResponse;
        /*
         * Destruktor
         */
        virtual ~Response();
        /*
         * Akcpetacja wizytatora klienta
         * @param visitor Wizytator
         */
        virtual void accept(ClientVisitor& visitor) const = 0;
        /*
         * Pobranie kodu statusu
         * @return Kod statusu wiadomosci
         */
        int getStatus() const;
        /*
         * Pobranie tresci odpowiedzi
         * @return Tresc odpowiedzi
         */
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


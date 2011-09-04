/* 
 * File:   NewMsgResponse.hpp
 * Author: Pawel
 *
 * Deklaracja klasy NewMsgResponse
 * Created on 7 styczeń 2011, 20:20
 */

#ifndef NEWMSGRESPONSE_HPP
#define	NEWMSGRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje odpowiedz na zadanie dodania nowej wiadomosci do subskrypcji
     */
    class NewMsgResponse: public Response, public RegisterSerializeable<NewMsgResponse, Response> {
    public:
        /*
         * Konstruktor
         */
        NewMsgResponse();
        /*
         * Konstruktor
         * @param status Kod odpowiedzi
         * @param answer Tresc odpowiedzi
         */
        NewMsgResponse(const int& status, const std::string& answer);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        NewMsgResponse(const NewMsgResponse& orig);
        /*
         * Destruktor
         */
        virtual ~NewMsgResponse();
        /*
         * Akcpetacja wizytatora klienta
         * @param visitor Wizytator
         */
        virtual void accept(ClientVisitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    };
}

#endif	/* NEWMSGRESPONSE_HPP */


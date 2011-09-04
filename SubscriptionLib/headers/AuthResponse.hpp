/* 
 * File:   AuthResponse.hpp
 * Author: Pawel
 *
 * Deklaracja klasy AuthResponse
 * Created on 7 styczeń 2011, 00:02
 */

#ifndef AUTHRESPONSE_HPP
#define	AUTHRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje odpowiedz na zadanie Auth
     */
    class AuthResponse: public Response, public RegisterSerializeable<AuthResponse, Response>  {
    public:
        /*
         * Konstruktor
         */
        AuthResponse();
        /*
         * Konstruktor
         * @param status Kod odpowiedzi
         * @param answer Tresc odpowiedzi
         */
        AuthResponse(const int& status, const std::string& answer);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        AuthResponse(const AuthResponse& orig);
        /*
         * Destruktor
         */
        virtual ~AuthResponse();
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

#endif	/* AUTHRESPONSE_HPP */


/* 
 * File:   AuthRequest.hpp
 * Author: Pawel
 *
 * Deklaracja klasy AuthRequest
 * Created on 6 styczeń 2011, 23:58
 */

#ifndef AUTHREQUEST_HPP
#define	AUTHREQUEST_HPP

#include "Request.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje zadnie autryzacji
     */
    class AuthRequest: public Request, public RegisterSerializeable<AuthRequest, Request> {
    public:
        /*
         * Konstruktor
         */
        AuthRequest();
        /*
         * Konstruktor
         * @param login Login
         * @param password Haslo
         */
        AuthRequest(const std::string& login, const std::string& password);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        AuthRequest(const AuthRequest& orig);
        /*
         * Destruktor
         */
        virtual ~AuthRequest();
        /*
         * Pobranie hasla
         * @return Haslo
         */
        std::string getPassword() const;
        /*
         * Akcpetacja wizytatora serwera
         * @param visitor Wizytator
         */
        virtual void accept(ServerVisitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    private:
        std::string _password;
    };
}

#endif	/* AUTHREQUEST_HPP */


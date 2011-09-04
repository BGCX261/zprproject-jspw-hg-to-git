/* 
 * File:   NewMsgRequest.hpp
 * Author: Pawel
 *
 * Deklaracja klasy NewMsgRequest
 * Created on 6 styczeń 2011, 23:59
 */

#ifndef NEWMSGREQUEST_HPP
#define	NEWMSGREQUEST_HPP

#include "Request.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje zadanie dodania nowej wiadomosci do subskrypcji
     */
    class NewMsgRequest: public Request, public RegisterSerializeable<NewMsgRequest, Request> {
    public:
        /*
         * Konstruktor
         */
        NewMsgRequest();
        /*
         * Konstruktor
         * @param login Login
         * @param subId Id subskrypcji
         * @param info Wiadomosc
         */
        NewMsgRequest(const std::string& login, const std::string& subId, const std::string& info);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        NewMsgRequest(const NewMsgRequest& orig);
        /*
         * Destruktor
         */
        virtual ~NewMsgRequest();
        /*
         * Pobranie tresci wiadomosci
         * @return Wiadomosc
         */
        std::string getInfo() const;
        /*
         * Pobranie id subskrypcji
         * @return Id subskrypcji
         */
        std::string getSubId() const;
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
        std::string _info;
        std::string _subId;
    };
}

#endif	/* NEWMSGREQUEST_HPP */


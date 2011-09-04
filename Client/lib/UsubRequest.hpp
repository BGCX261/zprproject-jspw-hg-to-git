/* 
 * File:   UsubRequest.hpp
 * Author: Pawel
 *
 * Deklaracja klasy UsubRequest
 * Created on 6 styczeń 2011, 23:58
 */

#ifndef USUBREQUEST_HPP
#define	USUBREQUEST_HPP

#include "Request.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje zadnie zatrzymania subskrypcji
     */
    class UsubRequest: public Request, public RegisterSerializeable<UsubRequest, Request> {
    public:
        /*
         * Konstruktor
         */
        UsubRequest();
        /*
         * Konstruktor
         * @param login Login
         * @param subId Id subskrupcji
         */
        UsubRequest(const std::string& login, const std::string& subId);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        UsubRequest(const UsubRequest& orig);
        /*
         * Destruktor
         */
        virtual ~UsubRequest();
        /*
         * Akcpetacja wizytatora serwera
         * @param visitor Wizytator
         */
        virtual void accept(ServerVisitor& visitor) const;
        /*
         * Pobranie id subskrypcji
         * @return Id subskrypcji
         */
        std::string getSubId() const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    private:
        std::string _subId;
    };
}

#endif	/* USUBREQUEST_HPP */


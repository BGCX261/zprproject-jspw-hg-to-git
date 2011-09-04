/* 
 * File:   SubsRequest.hpp
 * Author: Pawel
 *
 * Deklaracja klasy SubsRequest
 * Created on 6 styczeń 2011, 23:58
 */

#ifndef SUBSREQUEST_HPP
#define	SUBSREQUEST_HPP

#include "Request.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje zadanie subskrypcji
     */
    class SubsRequest: public Request, public RegisterSerializeable<SubsRequest, Request> {
    public:
        /*
         * Konstruktor
         */
        SubsRequest();
        /*
         * Konstruktor
         * @param login Login
         * @param subId Id subskrypcji
         */
        SubsRequest(const std::string& login, const std::string& subId);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        SubsRequest(const SubsRequest& orig);
        /*
         * Destruktor
         */
        virtual ~SubsRequest();
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

#endif	/* SUBSREQUEST_HPP */


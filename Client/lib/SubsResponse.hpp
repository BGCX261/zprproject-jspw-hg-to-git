/* 
 * File:   SubsResponse.hpp
 * Author: Pawel
 *
 * Deklaracja klasy SubsResponse
 * Created on 7 styczeń 2011, 00:02
 */

#ifndef SUBSRESPONSE_HPP
#define	SUBSRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje odpowiedz na zadanie subskrypcji
     */
    class SubsResponse: public Response, public RegisterSerializeable<SubsResponse, Response> {
    public:
        /*
         * Konstruktor
         */
        SubsResponse();
        /*
         * Konstruktor
         * @param status Kod odpowiedzi
         * @param answer Tresc odpowiedzi
         */
        SubsResponse(const int& status, const std::string& answer);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        SubsResponse(const SubsResponse& orig);
        /*
         * Destruktor
         */
        virtual ~SubsResponse();
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

#endif	/* SUBSRESPONSE_HPP */


/* 
 * File:   UsubResponse.hpp
 * Author: Pawel
 *
 * Deklaracja klasy UsubResponse
 * Created on 7 styczeń 2011, 00:02
 */

#ifndef USUBRESPONSE_HPP
#define	USUBRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje odpowiedz na zadniae zaprzestania subskrypcji
     */
    class UsubResponse: public Response, public RegisterSerializeable<UsubResponse, Response> {
    public:
        /*
         * Konstruktor
         */
        UsubResponse();
        /*
         * Konstruktor
         * @param status Kod odpowiedzi
         * @param answer Odpowiedz
         */
        UsubResponse(const int& status, const std::string& answer);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        UsubResponse(const UsubResponse& orig);
        /*
         * Destruktor
         */
        virtual ~UsubResponse();
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

#endif	/* USUBRESPONSE_HPP */


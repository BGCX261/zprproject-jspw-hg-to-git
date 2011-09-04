/* 
 * File:   MsgResponse.hpp
 * Author: Pawel
 *
 * Deklaracja klasy MsgResponse
 * Created on 7 styczeń 2011, 00:02
 */

#ifndef MSGRESPONSE_HPP
#define	MSGRESPONSE_HPP

#include "Response.hpp"

namespace SubscriptionLib
{
    /*
     * Reprezentuje nowa wiadomosc dodana do subskrypcji
     */
    class MsgResponse: public Response, public RegisterSerializeable<MsgResponse, Response> {
    public:
        /*
         * Konstruktor
         */
        MsgResponse();
        /*
         * Konstruktor
         * @param status Kod odpowiedzi
         * @param answer Tresc odpowiedzi
         * @param subId Id subskrypcji
         * @param info Wiadomosc
         */
        MsgResponse(const int& status, const std::string& answer, const std::string& subsId, const std::string& info);
        /*
         * Konstruktor kopiujaca
         * @param Kopiowany obiekt
         */
        MsgResponse(const MsgResponse& orig);
        /*
         * Destruktor
         */
        virtual ~MsgResponse();
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
         * Akcpetacja wizytatora klienta
         * @param visitor Wizytator
         */
        virtual void accept(ClientVisitor& visitor) const;
    protected:
        virtual std::string id() const;
        virtual bool doSerialize(Archive& archive) const;
        virtual bool doDeserialize(Archive& archive);
    private:
        std::string _info;
        std::string _subId;
    };
}

#endif	/* MSGRESPONSE_HPP */


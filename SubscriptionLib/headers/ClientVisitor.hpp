/* 
 * File:   ClientVisitor.hpp
 * Author: Pawel
 *
 * Deklaracja klasy ClientVisitor
 * Created on 11 styczeń 2011, 10:10
 */

#ifndef CLIENTVISITOR_HPP
#define	CLIENTVISITOR_HPP

namespace SubscriptionLib
{
    class AuthResponse;
    class MsgResponse;
    class NewMsgResponse;
    class SubsResponse;
    class UsubResponse;

    /*
     * Bazowa dla wizytatorow odpowiedzi
     */
    class ClientVisitor {
    public:
        /*
         * Destruktor
         */
        virtual ~ClientVisitor();
        virtual void handle(const AuthResponse& res) = 0;
        virtual void handle(const MsgResponse& res) = 0;
        virtual void handle(const NewMsgResponse& res) = 0;
        virtual void handle(const SubsResponse& res) = 0;
        virtual void handle(const UsubResponse& res) = 0;
    protected:
        ClientVisitor();
    };

}

#endif	/* CLIENTVISITOR_HPP */


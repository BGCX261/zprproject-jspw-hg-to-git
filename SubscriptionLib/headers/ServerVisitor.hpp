/* 
 * File:   ServerVisitor.hpp
 * Author: Pawel
 *
 * Created on 11 styczeń 2011, 10:11
 */

#ifndef SERVERVISITOR_HPP
#define	SERVERVISITOR_HPP

namespace SubscriptionLib
{
    class NewMsgRequest;
    class AuthRequest;
    class SubsRequest;
    class UsubRequest;

    class ServerVisitor {
    public:
        virtual ~ServerVisitor();
        virtual void handle(const NewMsgRequest& req) = 0;
        virtual void handle(const AuthRequest& req) = 0;
        virtual void handle(const SubsRequest& req) = 0;
        virtual void handle(const UsubRequest& req) = 0;
    protected:
        ServerVisitor();
    };
}

#endif	/* SERVERVISITOR_HPP */


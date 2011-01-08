/* 
 * File:   Visitor.hpp
 * Author: Pawel
 *
 * Created on 8 styczeń 2011, 21:10
 */

#ifndef VISITOR_HPP
#define	VISITOR_HPP

namespace SubscriptionLib
{
    class AuthResponse;
    class MsgResponse;
    class NewMsgResponse;
    class SubsResponse;
    class UsubResponse;
    class NewMsgRequest;
    class AuthRequest;
    class SubsRequest;
    class UsubRequest;
    
    class Visitor {
    public:
        virtual void handle(const AuthResponse& res) = 0;
        virtual void handle(const MsgResponse& res) = 0;
        virtual void handle(const NewMsgResponse& res) = 0;
        virtual void handle(const SubsResponse& res) = 0;
        virtual void handle(const UsubResponse& res) = 0;
        virtual void handle(const NewMsgRequest& req) = 0;
        virtual void handle(const AuthRequest& req) = 0;
        virtual void handle(const SubsRequest& req) = 0;
        virtual void handle(const UsubRequest& req) = 0;
    protected:
        Visitor();
    };
}

#endif	/* VISITOR_HPP */


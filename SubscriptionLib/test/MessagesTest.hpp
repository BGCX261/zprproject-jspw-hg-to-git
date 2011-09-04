/* 
 * File:   MessagesTest.hpp
 * Author: Pawel
 *
 * Created on 19 styczeń 2011, 21:07
 */

#ifndef MESSAGESTEST_HPP
#define	MESSAGESTEST_HPP

#include <boost/test/unit_test.hpp>

#include <boost/test/floating_point_comparison.hpp>
#include <boost/shared_ptr.hpp>
#include "Messages.hpp"
#include "StringArchive.hpp"
#include <string>

using namespace SubscriptionLib;
using namespace std;

class MessagesTest {
public:
    MessagesTest(string login, string subId, string password, string answer, string info, int status) :
        _login(login), _subId(subId), _password(password), _answer(answer), _info(info), _status(status) {}
    void msgResponse() {
        MsgResponse msg(_status, _answer, _subId, _info);
        BOOST_CHECK_EQUAL(_status, msg.getStatus());
        BOOST_CHECK_EQUAL(_answer, msg.getAnswer());
        BOOST_CHECK_EQUAL(_subId, msg.getSubId());
        BOOST_CHECK_EQUAL(_info, msg.getInfo());
    }
    void msgResponseSerialize() {
        MsgResponse msg(_status, _answer, _subId, _info);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Response::deserialize(s2));
        StringArchive s3(ms);
        Response::PResponse pss(Response::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<MsgResponse*>(pss.get()));
        MsgResponse* ps = static_cast<MsgResponse*>(pss.get());
        BOOST_CHECK_EQUAL(_status, ps->getStatus());
        BOOST_CHECK_EQUAL(_answer, ps->getAnswer());
        BOOST_CHECK_EQUAL(_subId, ps->getSubId());
        BOOST_CHECK_EQUAL(_info, ps->getInfo());
    }
    void authResponse() {
        AuthResponse msg(_status, _answer);
        BOOST_CHECK_EQUAL(_status, msg.getStatus());
        BOOST_CHECK_EQUAL(_answer, msg.getAnswer());
    }
    void authResponseSerialize() {
        AuthResponse msg(_status, _answer);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Response::deserialize(s2));
        StringArchive s3(ms);
        Response::PResponse pss(Response::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<AuthResponse*>(pss.get()));
        AuthResponse* ps = static_cast<AuthResponse*>(pss.get());
        BOOST_CHECK_EQUAL(_status, ps->getStatus());
        BOOST_CHECK_EQUAL(_answer, ps->getAnswer());
    }
    void newmsgResponse() {
        NewMsgResponse msg(_status, _answer);
        BOOST_CHECK_EQUAL(_status, msg.getStatus());
        BOOST_CHECK_EQUAL(_answer, msg.getAnswer());
    }
    void newmsgResponseSerialize() {
        NewMsgResponse msg(_status, _answer);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Response::deserialize(s2));
        StringArchive s3(ms);
        Response::PResponse pss(Response::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<NewMsgResponse*>(pss.get()));
        NewMsgResponse* ps = static_cast<NewMsgResponse*>(pss.get());
        BOOST_CHECK_EQUAL(_status, ps->getStatus());
        BOOST_CHECK_EQUAL(_answer, ps->getAnswer());
    }
    void subsResponse() {
        SubsResponse msg(_status, _answer);
        BOOST_CHECK_EQUAL(_status, msg.getStatus());
        BOOST_CHECK_EQUAL(_answer, msg.getAnswer());
    }
    void subsResponseSerialize() {
        SubsResponse msg(_status, _answer);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Response::deserialize(s2));
        StringArchive s3(ms);
        Response::PResponse pss(Response::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<SubsResponse*>(pss.get()));
        SubsResponse* ps = static_cast<SubsResponse*>(pss.get());
        BOOST_CHECK_EQUAL(_status, ps->getStatus());
        BOOST_CHECK_EQUAL(_answer, ps->getAnswer());
    }
    void usubResponse() {
        UsubResponse msg(_status, _answer);
        BOOST_CHECK_EQUAL(_status, msg.getStatus());
        BOOST_CHECK_EQUAL(_answer, msg.getAnswer());
    }
    void usubResponseSerialize() {
        UsubResponse msg(_status, _answer);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Response::deserialize(s2));
        StringArchive s3(ms);
        Response::PResponse pss(Response::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<UsubResponse*>(pss.get()));
        UsubResponse* ps = static_cast<UsubResponse*>(pss.get());
        BOOST_CHECK_EQUAL(_status, ps->getStatus());
        BOOST_CHECK_EQUAL(_answer, ps->getAnswer());
    }
    void authRequest() {
        AuthRequest msg(_login, _password);
        BOOST_CHECK_EQUAL(_login, msg.getLogin());
        BOOST_CHECK_EQUAL(_password, msg.getPassword());
    }
    void authRequestSerialize() {
        AuthRequest msg(_login, _password);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Request::deserialize(s2));
        StringArchive s3(ms);
        Request::PRequest pss(Request::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<AuthRequest*>(pss.get()));
        AuthRequest* ps = static_cast<AuthRequest*>(pss.get());
        BOOST_CHECK_EQUAL(_login, ps->getLogin());
        BOOST_CHECK_EQUAL(_password, ps->getPassword());
    }
    void subsRequest() {
        SubsRequest msg(_login, _subId);
        BOOST_CHECK_EQUAL(_login, msg.getLogin());
        BOOST_CHECK_EQUAL(_subId, msg.getSubId());
    }
    void subsRequestSerialize() {
        SubsRequest msg(_login, _subId);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Request::deserialize(s2));
        StringArchive s3(ms);
        Request::PRequest pss(Request::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<SubsRequest*>(pss.get()));
        SubsRequest* ps = static_cast<SubsRequest*>(pss.get());
        BOOST_CHECK_EQUAL(_login, ps->getLogin());
        BOOST_CHECK_EQUAL(_subId, ps->getSubId());
    }
    void usubRequest() {
        UsubRequest msg(_login, _subId);
        BOOST_CHECK_EQUAL(_login, msg.getLogin());
        BOOST_CHECK_EQUAL(_subId, msg.getSubId());
    }
    void usubRequestSerialize() {
        UsubRequest msg(_login, _subId);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Request::deserialize(s2));
        StringArchive s3(ms);
        Request::PRequest pss(Request::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<UsubRequest*>(pss.get()));
        UsubRequest* ps = static_cast<UsubRequest*>(pss.get());
        BOOST_CHECK_EQUAL(_login, ps->getLogin());
        BOOST_CHECK_EQUAL(_subId, ps->getSubId());
    }
    void newmsgRequest() {
        NewMsgRequest msg(_login, _subId, _info);
        BOOST_CHECK_EQUAL(_login, msg.getLogin());
        BOOST_CHECK_EQUAL(_subId, msg.getSubId());
        BOOST_CHECK_EQUAL(_info, msg.getInfo());
    }
    void newmsgRequestSerialize() {
        NewMsgRequest msg(_login, _subId, _info);
        StringArchive sa;
        BOOST_REQUIRE_NO_THROW(msg.serialize(sa));
        string ms = sa.getStr();
        StringArchive s2(ms);
        BOOST_REQUIRE_NO_THROW(Request::deserialize(s2));
        StringArchive s3(ms);
        Request::PRequest pss(Request::deserialize(s3));
        BOOST_REQUIRE_NO_THROW(static_cast<NewMsgRequest*>(pss.get()));
        NewMsgRequest* ps = static_cast<NewMsgRequest*>(pss.get());
        BOOST_CHECK_EQUAL(_login, ps->getLogin());
        BOOST_CHECK_EQUAL(_subId, ps->getSubId());
        BOOST_CHECK_EQUAL(_info, ps->getInfo());
    }
private:
    std::string _login;
    std::string _subId;
    std::string _password;
    std::string _answer;
    std::string _info;
    int _status;
};

#endif	/* MESSAGESTEST_HPP */


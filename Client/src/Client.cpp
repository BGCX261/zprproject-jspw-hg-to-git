/* 
 * File:   Client.cpp
 * Author: Pawel
 *
 * Implementacja klasy Client
 * Created on 11 styczeń 2011, 13:09
 */

#include "Client.hpp"
#include "Terminal.hpp"
#include "IoService.hpp"
#include "lib/AuthResponse.hpp"
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

namespace Client
{
    Client::Client(ConditionVariable::PCondVar condVar, std::string hostIp, std::string hostPort) :
        _pCondVar(condVar), _hostIp(hostIp), _hostPort(hostPort), _socket(IoService::getInstance()->getService()),
        _resolver(IoService::getInstance()->getService()), _query(boost::asio::ip::tcp::v4(), _hostIp, _hostPort),
        _bufSize(8), _asynBufSize(8) {
        _it = _resolver.resolve(_query);
    }

    Client::~Client() {
    }

    void Client::connect() {
        _socket.connect(*_it);
    }

    void Client::disconnect() {
        _socket.close();
    }

    void Client::write(SubscriptionLib::Request::PRequest req) {
        SubscriptionLib::StringArchive archive;
        req->serialize(archive);
        boost::asio::write(_socket, boost::asio::buffer(archive.getStr()));
    }

    void Client::doRead() {
        _pCondVar->notify_one();
        boost::asio::async_read(_socket, boost::asio::buffer(_asynBufSize),
                        boost::bind(&Client::handleReadHeader, this, boost::asio::placeholders::error));
    }

    void Client::read() {
        boost::asio::read(_socket, boost::asio::buffer(_bufSize));
        _bufChar.resize(boost::lexical_cast<int>(std::string(_bufSize.begin(), _bufSize.end())));
        boost::asio::read(_socket, boost::asio::buffer(_bufChar));
        SubscriptionLib::StringArchive archive(std::string(_bufSize.begin(), _bufSize.end()) + std::string(_bufChar.begin(), _bufChar.end()));
        _response = SubscriptionLib::Response::deserialize(archive);
    }

    void Client::readAsynch() {
        IoService::getInstance()->getService().post(boost::bind(&Client::doRead, this));
        IoService::getInstance()->run();
    }

    void Client::handleReadHeader(const boost::system::error_code& ec) {
        if(!ec) {
            _asynBufChar.resize(boost::lexical_cast<int>(std::string(_asynBufSize.begin(), _asynBufSize.end())));
            boost::asio::async_read(_socket, boost::asio::buffer(_asynBufChar),
                        boost::bind(&Client::handleReadBody, this, boost::asio::placeholders::error));
            IoService::getInstance()->run();
        }
    }

    void Client::handleReadBody(const boost::system::error_code& ec) {
        if(!ec) {
            SubscriptionLib::StringArchive archive(std::string(_asynBufSize.begin(), _asynBufSize.end()) + std::string(_asynBufChar.begin(), _asynBufChar.end()));
            _response = SubscriptionLib::Response::deserialize(archive);
            _pCondVar->notify_one();
        }
    }

    bool Client::isNewResponse() {
        return _response.get() != NULL;
    }

    bool Client::tryGetResponse(SubscriptionLib::Response::PResponse& pRes) {
        if (_response.get() != NULL) {
            pRes = _response;
            _response.reset();
            return true;
        }
        return false;
    }

    bool Client::connected() {
        return _socket.is_open();
    }

}



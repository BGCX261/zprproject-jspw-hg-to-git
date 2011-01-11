/* 
 * File:   Client.hpp
 * Author: Pawel
 *
 * Created on 11 styczeń 2011, 13:09
 */

#ifndef CLIENT_HPP
#define	CLIENT_HPP

#include "Request.hpp"
#include "Response.hpp"
#include <boost/asio.hpp>

using namespace SubscriptionLib;

class Client {
public:
    Client(std::string hostIp, std::string hostPort);
    virtual ~Client();

    void connect();
    void write(Request::PRequest req);
    void read();

private:
    boost::asio::io_service _ioService;
    boost::asio::ip::tcp::socket _socket;
    std::string _hostIp;
    std::string _hostPort;

};

#endif	/* CLIENT_HPP */


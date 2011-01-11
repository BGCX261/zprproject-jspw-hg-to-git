/* 
 * File:   Client.cpp
 * Author: Pawel
 * 
 * Created on 11 styczeń 2011, 13:09
 */

#include "Client.hpp"

Client::Client(std::string hostIp, std::string hostPort){// :
   // _hostIp(hostIp), _hostPort(hostPort), _ioService(), _socket(_ioService) {
}

Client::~Client() {
}

void Client::connect() {
    //boost::asio::ip::tcp::resolver resolver( _ioService );
    //boost::asio::ip::tcp::resolver::query query( boost::asio::ip::tcp::v4(), _hostIp, _hostPort );
    //boost::asio::ip::tcp::resolver::iterator it = resolver.resolve( query );
    //_socket.connect(*it);
}



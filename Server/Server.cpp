/*
 * Server.cpp
 *
 *  Created on: Jan 5, 2011
 *      Author: asia
 */

#include "Server.h"
#include <iostream>
#include <boost/lexical_cast.hpp>
namespace server{

Server::PServer Server::_pInstance;


/**
 * returns instance of server
 * if does not exist- creates new object
 * */
Server::PServer Server::getInstance() {
	   if(_pInstance == NULL){
	        _pInstance = PServer(new Server(5000));
	   }
	    return _pInstance;
}


/***
 * constuctor
 * */
Server::Server(int port) : _io_service(), _port(port),  _acceptor(_io_service, tcp::endpoint(tcp::v4(), _port)),
	      _timer(_io_service)
{
	SubList::getInstance()->addNewSubscription(std::string("s1"), 1);
	SubList::getInstance()->addNewSubscription(std::string("s2"), 1);
	std::cout<<SubList::getInstance()->toString();
	 //asynchronous waiting for clients
	 ptr_chat_session new_session(new RequestSession(_io_service));
	    _acceptor.async_accept(new_session->socket(),
	        boost::bind(&Server::handle_accept, this, new_session,
	          boost::asio::placeholders::error));

    // Start the timer used to generate outgoing frames.
    _timer.expires_from_now(boost::posix_time::seconds(5));
    _timer.async_wait(boost::bind(&Server::handle_timer, this));
    _io_service.run();
}

Server::~Server() {

}

void Server::handle_accept(ptr_chat_session session,
	      const boost::system::error_code& error){
    if (!error)
    {
      session->start();
      ptr_chat_session new_session(new RequestSession(_io_service));
      _acceptor.async_accept(new_session->socket(),
          boost::bind(&Server::handle_accept, this, new_session,
            boost::asio::placeholders::error));
    }
}

void Server::handle_timer(){
	MsgSender::deliverAfterTimeout();
    _timer.expires_from_now(boost::posix_time::seconds(1));
    _timer.async_wait(boost::bind(&Server::handle_timer, this));
}

void Server::start(){
}


void Server::stop(){

}

}

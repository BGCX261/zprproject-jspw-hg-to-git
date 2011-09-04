/*
 * Auth_req.cpp
 *
 *  Created on: Jan 19, 2011
 *      Author: asia
 */

#include "Auth_req.h"

Auth_req::Auth_req(boost::asio::ip::tcp::socket* socket) {
	socket_ = socket;
}

Auth_req::~Auth_req() {
}

void Auth_req::operator()(const SubscriptionLib::AuthRequest& req){
    UserConnection* user = Users::getInstance()->getUser(req.getLogin());
    if(user==NULL){
  	  user = new UserConnection(req.getLogin(), req.getPassword(), socket_);
  	  Users::getInstance()->addUser(user);
  	  SubscriptionLib::AuthResponse response(0, std::string("User is authorized\n"));
  	  MsgSender::deliver(response, user->getsocket());
    }
    else{
  	  SubscriptionLib::AuthResponse response(1, std::string("ERROR, User with this id is logged to the server\n"));
  	  MsgSender::deliver(response, user->getsocket());
    }
}

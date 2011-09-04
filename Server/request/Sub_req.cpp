/*
 * Sub_req.cpp
 *
 *  Created on: Jan 19, 2011
 *      Author: asia
 */

#include "Sub_req.h"

Sub_req::Sub_req(boost::asio::ip::tcp::socket* socket) {
	socket_ = socket;
}

Sub_req::~Sub_req() {
}

void Sub_req::operator()(const SubscriptionLib::SubsRequest& req){
	  UserConnection * user = Users::getInstance()->getUser(req.getLogin());
	  Subscription * subs = SubList::getInstance()->getSubscription(req.getSubId());
	  if(user!=NULL && subs!=NULL && socket_==user->getsocket() && !user->isContainsSubject(subs)){
	      	user->addSubject(subs);
	      	subs->addObserver(user);
	      	SubscriptionLib::SubsResponse response(0, std::string("Subs operation was succeed"));
	      	MsgSender::deliver(response, user->getsocket());
	  }else{
  		SubscriptionLib::SubsResponse response(1, std::string("Specified user or id does not exist"));
  		MsgSender::deliver(response, socket_);
	  }
}

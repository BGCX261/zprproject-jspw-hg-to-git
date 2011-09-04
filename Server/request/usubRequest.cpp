/*
 * usubRequest.cpp
 *
 *  Created on: Jan 19, 2011
 *      Author: asia
 */

#include "usubRequest.h"

usubRequest::usubRequest(boost::asio::ip::tcp::socket* socket) {
	socket_ = socket;
}

usubRequest::~usubRequest() {
}

void usubRequest::operator()(const SubscriptionLib::UsubRequest& req){
	  UserConnection * user = Users::getInstance()->getUser(req.getLogin());
	  Subscription * subs = SubList::getInstance()->getSubscription(req.getSubId());
	  if(user!=NULL && subs!=NULL &&socket_==user->getsocket() && user->isContainsSubject(subs)){
	      		user->removeSubject(subs);
	      		subs->removeObserver(user);
	      		SubscriptionLib::UsubResponse response(0, std::string("USubs operation was succeed"));
	      		MsgSender::deliver(response, user->getsocket());
	  }else{;
		  SubscriptionLib::UsubResponse response(1, std::string("User is not authorized |subscription with specified id is not exist | user is not subscribe this subscription"));
		  MsgSender::deliver(response, socket_);
	  }
}

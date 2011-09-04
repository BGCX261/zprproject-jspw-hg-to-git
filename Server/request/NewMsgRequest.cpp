/*
 * NewMsgRequest.cpp
 *
 *  Created on: Jan 19, 2011
 *      Author: asia
 */

#include "NewMsgRequest.h"

NewMsgRequest::NewMsgRequest() {
	// TODO Auto-generated constructor stub

}

NewMsgRequest::~NewMsgRequest() {
	// TODO Auto-generated destructor stub
}

void NewMsgRequest::operator()( boost::asio::ip::tcp::socket*socket_, const SubscriptionLib::NewMsgRequest& req){
	  Subscription* subs = SubList::getInstance()->getSubscription(req.getSubId());
	  UserConnection* user = Users::getInstance()->getUser(req.getLogin());
	  if(subs!=NULL && user!=NULL && socket_==user->getsocket() && user->isContainsSubject(subs)){
	      		SubscriptionLib::MsgResponse *response = new SubscriptionLib::MsgResponse(0, req.getInfo(), req.getSubId(), req.getInfo());
	      		subs->addNews(*response);
	      		SubscriptionLib::NewMsgResponse res(0, std::string("Message was sent"));
	      		MsgSender::deliver(res, user->getsocket());
	  }else{
	      		SubscriptionLib::NewMsgResponse response(1, std::string("User is not authorized or subscription with specified id is not exist"));
	      		MsgSender::deliver(response, socket_);
	 }
}

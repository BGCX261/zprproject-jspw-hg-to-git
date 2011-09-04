/*
 * NewMsgRequest.h
 *
 *  Created on: Jan 19, 2011
 *      Author: asia
 */

#ifndef NEWMSGREQUEST_H_
#define NEWMSGREQUEST_H_

#include "../Users.h"
#include "../MsgSender.h"
#include <SubsRequest.hpp>
#include <boost/asio.hpp>
#include <MsgResponse.hpp>
#include <NewMsgRequest.hpp>

class NewMsgRequest {
public:
	NewMsgRequest();
	virtual ~NewMsgRequest();
	void operator()( boost::asio::ip::tcp::socket*, const SubscriptionLib::NewMsgRequest& req);
};

#endif /* NEWMSGREQUEST_H_ */

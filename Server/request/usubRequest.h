/*
 * usubRequest.h
 *
 *  Created on: Jan 19, 2011
 *      Author: asia
 */

#ifndef USUBREQUEST_H_
#define USUBREQUEST_H_

#include "../Users.h"
#include "../MsgSender.h"
#include <SubsRequest.hpp>
#include <boost/asio.hpp>
#include <MsgResponse.hpp>

class usubRequest {
	private:
	boost::asio::ip::tcp::socket* socket_;
public:
	usubRequest(boost::asio::ip::tcp::socket* socket_);
	virtual ~usubRequest();
	void operator()(const SubscriptionLib::UsubRequest& req);
};

#endif /* USUBREQUEST_H_ */

/*
 * Sub_req.h
 *
 *  Created on: Jan 19, 2011
 *      Author: asia
 */

#ifndef SUB_REQ_H_
#define SUB_REQ_H_

#include "../Users.h"
#include "../MsgSender.h"
#include <SubsRequest.hpp>
#include <boost/asio.hpp>
#include <MsgResponse.hpp>

class Sub_req {

private:
	boost::asio::ip::tcp::socket* socket_;
public:
	Sub_req(boost::asio::ip::tcp::socket* socket_);
	~Sub_req();
	void operator()(const SubscriptionLib::SubsRequest& req);
};

#endif /* SUB_REQ_H_ */

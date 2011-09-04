/*
 * Auth_req.h
 *
 *  Created on: Jan 19, 2011
 *      Author: asia
 */

#ifndef AUTH_REQ_H_
#define AUTH_REQ_H_

#include "../Users.h"
#include "../MsgSender.h"
#include <AuthRequest.hpp>
#include <boost/asio.hpp>

using namespace server;

class Auth_req {
	private:
		boost::asio::ip::tcp::socket* socket_;
	public:
		Auth_req(boost::asio::ip::tcp::socket* socket_);
		~Auth_req();

	void operator()(const SubscriptionLib::AuthRequest& req);
};

#endif /* AUTH_REQ_H_ */

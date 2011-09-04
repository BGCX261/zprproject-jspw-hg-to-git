/*
 * RequestSession.h
 *
 *  Created on: Jan 15, 2011
 *      Author: asia
 */

#ifndef REQUESTSESSION_H_
#define REQUESTSESSION_H_

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <StringArchive.hpp>
#include <Request.hpp>

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

#include <SubsRequest.hpp>
#include <UsubRequest.hpp>
#include <AuthRequest.hpp>
#include <NewMsgRequest.hpp>
#include <NewMsgResponse.hpp>
#include <MsgResponse.hpp>
#include <AuthResponse.hpp>
#include <SubsResponse.hpp>
#include <UsubResponse.hpp>
#include <Request.hpp>

#include "RequestMessage.h"
#include "Auth_req.h"
#include "Sub_req.h"
#include "NewMsgRequest.h"
#include "usubRequest.h"
#include "../Server.h"
#include "../Users.h"
#include "../subscriptions/Subscriptionss.h"
#include "../MsgSender.h"

namespace server{

class RequestSession  : public boost::enable_shared_from_this<RequestSession>
{
	public:
		RequestSession(boost::asio::io_service& io_service);
		~RequestSession();
		void start();
		boost::asio::ip::tcp::socket& socket();
		void handle_read_header(const boost::system::error_code& error);
		void handle_read_body(const boost::system::error_code& error);
		boost::asio::ip::tcp::socket socket_;
		RequestMessage read_msg_;
		RequestMessage write_msg;
		bool firsTime;

		struct Worker: public SubscriptionLib::ServerVisitor {
			boost::asio::ip::tcp::socket* socket_;
			Worker(int, boost::asio::ip::tcp::socket* socket_);
			~Worker();
			void play(const std::string &);

			void handle(const SubscriptionLib::NewMsgRequest& req);
            void handle(const SubscriptionLib::AuthRequest& req);
            void handle(const SubscriptionLib::SubsRequest& req);
            void handle(const SubscriptionLib::UsubRequest& req);
		};

		Worker _worker;
};
}
#endif /* REQUESTSESSION_H_ */

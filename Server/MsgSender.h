/*
 * MsgSender.h
 *
 *  Created on: Jan 11, 2011
 *      Author: asia
 */

#ifndef MSGSENDER_H_
#define MSGSENDER_H_


#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include <Request.hpp>
#include <StringArchive.hpp>

#include "User.h"
#include "Server.h"

namespace server {

	class MsgSender {
	public:
		MsgSender(const std::string msg, boost::asio::ip::tcp::socket* socket);
		~MsgSender();

		/**
		 * ent msg with response to user
		 * */
		static void deliver(const std::string& msg, boost::asio::ip::tcp::socket*);

		/**
		 * sent msg with response object to user
		 * */
		static void deliver(const SubscriptionLib::Response &response, boost::asio::ip::tcp::socket*);

		/**
		 * Send msg for user after timeout
		 * **/
		static void deliverAfterTimeout();

	private:
		const std::string msg;
		boost::asio::ip::tcp::socket* socket_;
	};

}

#endif /* MSGSENDER_H_ */

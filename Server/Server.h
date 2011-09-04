/*
 * Server.h
 *
 *  Created on: Jan 5, 2011
 *      Author: asia
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>
#include <boost/enable_shared_from_this.hpp>

#include <ServerVisitor.hpp>
#include <UsubRequest.hpp>
#include <SubsRequest.hpp>
#include <SubsResponse.hpp>
#include <AuthResponse.hpp>
#include <MsgResponse.hpp>
#include <string>

#include "User.h"
#include "subscriptions/Subscription.h"
#include "subscriptions/SubscriptionFactory.h"
#include "request/RequestMessage.h"
#include "request/RequestSession.h"

namespace server {

using boost::asio::ip::tcp;
class RequestSession;

typedef boost::shared_ptr<tcp::socket> tcp_socket_ptr;
typedef boost::shared_ptr<boost::asio::deadline_timer> timer_ptr;
typedef boost::shared_ptr<RequestSession> ptr_chat_session;




class Server {
	public:
		void start();
		static void stop();
		~Server();

		/**
		 * Accepts users connections
		 * **/
		void handle_accept(ptr_chat_session session, const boost::system::error_code& error);

		/**
		 * Action after timeot(send msgs to users)
		 * */
		void handle_timer();
		typedef boost::shared_ptr<Server> PServer;

		/**
		 * returns the instance of Sever (server is a singleton)
		 * */
		static PServer getInstance();

	private:
		Server(int);
		int _port;
		static PServer _pInstance;
		boost::asio::io_service _io_service;
		boost::asio::ip::tcp::acceptor _acceptor;
		boost::asio::deadline_timer _timer;
};


}
#endif /* SERVER_H_ */

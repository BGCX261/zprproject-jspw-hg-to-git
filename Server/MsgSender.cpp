/*
 * MsgSender.cpp
 *
 *  Created on: Jan 11, 2011
 *      Author: asia
 */

#include "MsgSender.h"

namespace server {

	MsgSender::MsgSender(const std::string str, boost::asio::ip::tcp::socket* socket) :msg(str){
	}

	MsgSender::~MsgSender() {
	}

	void MsgSender::deliver(const SubscriptionLib::Response &response, boost::asio::ip::tcp::socket* socket){
		SubscriptionLib::StringArchive s;
		response.serialize(s);
		std::string str = s.getStr();
		deliver(str, socket);
	}

	void MsgSender::deliver(const std::string& message,  boost::asio::ip::tcp::socket* socket){
		std::cout<<message;
		boost::asio::write( *socket, boost::asio::buffer(message));
		std::cout<<"wyszedl\n";
	}

	void MsgSender::deliverAfterTimeout(){
		std::list<UserConnection *> _users = Users::getInstance()->getUsers();
		std::list<UserConnection *>::const_iterator it;
		for(it=_users.begin(); it!=_users.end(); ++it){
			std::list<SubscriptionLib::MsgResponse> _msgs = (*it)->newNews();
			std::list<SubscriptionLib::MsgResponse>::const_iterator newsIt;
			for(newsIt = _msgs.begin(); newsIt != _msgs.end(); ++newsIt){
				deliver((*newsIt), (*it)->getsocket());
			}
			(*it)->clear();
		}

	}
}

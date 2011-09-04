/*
 * RequestSession.cpp
 *
 *  Created on: Jan 15, 2011
 *      Author: asia
 */

#include "RequestSession.h"

namespace server{
  RequestSession::RequestSession(boost::asio::io_service& io_service)
    : socket_(io_service), _worker(1, &socket_)
  {
	  firsTime = true;
  }

RequestSession::~RequestSession() {
}

boost::asio::ip::tcp::socket& RequestSession::socket()
{
  return socket_;
}

void RequestSession::start()
{
	boost::asio::async_read(socket_,
      boost::asio::buffer(read_msg_.data(), RequestMessage::header_length),
      boost::bind(&RequestSession::handle_read_header, shared_from_this(),
        boost::asio::placeholders::error));
}

void RequestSession::handle_read_header(const boost::system::error_code& error)
{
  if (!error && read_msg_.decode_header())
  {
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        boost::bind(&RequestSession::handle_read_body, shared_from_this(),
          boost::asio::placeholders::error));
  }
  else{
	  std::cout<<error.message()<<"\n";
  }
}

void RequestSession::handle_read_body(const boost::system::error_code& error)
{
  if (!error)
  {
	 using namespace SubscriptionLib;
	 read_msg_.data_[read_msg_.header_length + read_msg_.body_length_]= '\0';
  	 std::string msg= std::string(read_msg_.data());
  	 _worker.play(msg);
   }
  else{
	  std::cout<<error.message()<<"\n";
  }
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.data(), RequestMessage::header_length),
        boost::bind(&RequestSession::handle_read_header, shared_from_this(),
          boost::asio::placeholders::error));
  }

  RequestSession::Worker::Worker(int i, boost::asio::ip::tcp::socket* socket_){
	  RequestSession::Worker::socket_ = socket_;
  }

  RequestSession::Worker::~Worker(){
  }

  void RequestSession::Worker::play(const std::string &message){
	  SubscriptionLib::StringArchive stringArchive(message);
	  std::auto_ptr<SubscriptionLib::Request> req = SubscriptionLib::Request::deserialize(stringArchive);
	  req->accept(*this);
  }

/***
 * Dodanie nowego usera
 * */
  void RequestSession::Worker::handle(const SubscriptionLib::AuthRequest& request) {
	    Auth_req req(socket_);
	    boost::thread thr(&Auth_req::operator(), req, request);
  }


  void RequestSession::Worker::handle(const SubscriptionLib::SubsRequest& request) {
	  Sub_req req(socket_);
	  boost::thread thr(&Sub_req::operator(), req, request);
  }

  void RequestSession::Worker::handle(const SubscriptionLib::UsubRequest& request) {
	  usubRequest req(socket_);
	  boost::thread thr(&usubRequest::operator(), req, request);
  }

  void RequestSession::Worker::handle(const SubscriptionLib::NewMsgRequest& req) {
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
}

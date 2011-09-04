/*
 * UserConnection.cpp
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#include "User.h"
#include <string>
#include <iostream>


namespace server {

UserConnection::UserConnection(const std::string& u, const std::string& c): _login(u), _pass(c){}

UserConnection::UserConnection(const std::string& u, const std::string& c, boost::asio::ip::tcp::socket* socket)
: _login(u), _pass(c){
	_socket = socket;
}

UserConnection::~UserConnection() {
}


std::string UserConnection::getLogin() const
{
    return _login;
}

std::string UserConnection::getPass() const
{
    return _pass;
}


void UserConnection::setLogin(const std::string login)
{
    this->_login = login;
}

void UserConnection::setPass(const std::string pass)
{
    this->_pass = pass;
}

boost::asio::ip::tcp::socket* UserConnection::getsocket(){
	return _socket;
}

// po tym jak cos sie zmieni w obiekcie
void UserConnection::update(){
	boost::mutex::scoped_lock lock(subjects_mutex);
	std::map<Subscription *,int>::iterator it;
	for(it = _subjects.begin(); it != _subjects.end(); ++it ){
		if((*it).first->getMessNr() != (*it).second){
			int diff = ((*it).first->getMessNr() != (*it).second);
			_subjects[(*it).first] += 1;
			for(int i=1; i<=diff; ++i){
				boost::mutex::scoped_lock lock(news_mutex);
				SubscriptionLib::MsgResponse msg = (*it).first->getNews(diff-i);
				news.push_back(msg);
			}
		}
	}
}


void UserConnection::addSubject(Subscription * sub){
	//boost::mutex::scoped_lock lock(subjects_mutex);
	_subjects[sub] = sub->getMessNr();
}

/**
 *
 * **/
void UserConnection::removeSubject(Subscription* sub){ //przerobic na mape
	_subjects.erase(sub);
}

/**
 * checks is there is a subscription wit the same id as a subscription given as a function parameter
 * @ returns true - contains
 * @ false - doesnot constain
 * */
bool UserConnection::isContainsSubject(Subscription *sub){
	boost::mutex::scoped_lock lock(subjects_mutex);
	std::map<Subscription *, int>::const_iterator it;
		for(it=_subjects.begin(); it!= _subjects.end(); ++it){
			if((*it).first == sub){
				return true;
			}
		}
	return false;
}


/***
 * Responsible for sending all messages to user
 * */
std::list<SubscriptionLib::MsgResponse> UserConnection::newNews() const{
	return news;
}
void UserConnection::clear(){
	 news.clear();
}

}

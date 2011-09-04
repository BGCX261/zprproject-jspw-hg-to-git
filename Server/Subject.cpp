/*
 * Subject.cpp
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#include "Subject.h"
#include "User.h"
#include <iostream>

namespace server {

	Subject::~Subject() {
	}

	/**
	 * Inform all observers that was new msg in this subscription
	 * */
	void Subject::notify(){
		boost::mutex::scoped_lock lock(obs_mutex);
		std::list<Observer *>::iterator it;
		for(it = obs_.begin(); it != obs_.end(); ++it)
			(*it)->update();
	}
	/***
	 * Add observer to list of users who observe this subscription
	 * */
	void Subject::addObserver(Observer *o){
	//	boost::mutex::scoped_lock lock(obs_mutex);
		obs_.push_back(o);
	}

	/***
	 * Remove observer for list of users who observe this subscription
	 * */
	void Subject::removeObserver(Observer *o){
		obs_.remove(o);
	}

	/**
	 * Add new msg to this subscription, which will by sent to users
	 * */
	void Subject::addNews(const SubscriptionLib::MsgResponse &msg){
		boost::mutex news_mutex;
		news.push_back(msg);
		notify();
	}

	/**
	 * Returns nr of messages in this subjects
	 * */
	int Subject::getMessNr() const{
		return news.size();
	}

	/**
	 * Returns message with specified number
	 * msg from this subscription t client
	 * **/
	const SubscriptionLib::MsgResponse& Subject::getNews(int i)const{
		boost::mutex news_mutex;
		if(i>news.size()){
			throw new std::exception();
		}
		return news[(int)news.size()- i-1];
	}
}

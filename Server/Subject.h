/*
 * Subject.h
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "Observer.h"
//#include "UserConnection.h"
#include <list>
#include <string>
#include <vector>
#include <boost/thread/mutex.hpp>
#include <MsgResponse.hpp>

namespace server {

	class Subject {
	public:
		Subject(){};
		~Subject();
		void notify();
		void addObserver(Observer *o);
		void removeObserver(Observer *o);
		void addNews(const SubscriptionLib::MsgResponse &);
		int getMessNr() const;
		const SubscriptionLib::MsgResponse& getNews(int)const;

	private:
		std::list<Observer *> obs_;
		std::vector<SubscriptionLib::MsgResponse> news;
		boost::mutex obs_mutex;
		boost::mutex news_mutex;
	};
}

#endif /* SUBJECT_H_ */

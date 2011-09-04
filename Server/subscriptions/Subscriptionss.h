/*
 * Subscriptions.h
 *
 *  Created on: Jan 17, 2011
 *      Author: asia
 */

#ifndef SUBSCRIPTIONS_H_
#define SUBSCRIPTIONS_H_

#include <boost/shared_ptr.hpp>
#include "Subscription.h"
#include "SubscriptionFactory.h"
#include <list>
#include <iostream>

namespace server {

	class SubList {
	public:
		~SubList();

		/**
		 * Adds new subscription to available subscriptions list
		 * */
		void addSubscrtiption(Subscription *);

		/**
		 * Adds new subscription to available subscriptions list
		 * */
		void addNewSubscription(const std::string& id, int);

		/***
		 * Remove subscription from available subscriptions list
		 * */
		void removeSubscription(Subscription *);

		/**
		 * Returns subscription with specified id
		 * */
		Subscription* getSubscription(const std::string& name) const;
		std::string toString();
		int nrOfSub();

		typedef boost::shared_ptr<SubList> PSubscriptions;

		/**
		 * Returns instance of subscriptions list
		 * */
		static PSubscriptions getInstance();

	private:
		SubList();
		static PSubscriptions _pInstance;
		std::list<Subscription *> _subjects;
	};

}

#endif /* SUBSCRIPTIONS_H_ */

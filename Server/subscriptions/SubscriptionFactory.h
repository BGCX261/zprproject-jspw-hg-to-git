/*
 * SubscriptionFactory.h
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#ifndef SUBSCRIPTIONFACTORY_H_
#define SUBSCRIPTIONFACTORY_H_

#include "Subscription.h"
#include "subscriptionTypes/TimeSubscription.h"
#include "subscriptionTypes/ProgrammerSuscription.h"
#include "subscriptionTypes/TextSubscription.h"
/**
 * Class is responsible for creating new subsctiption types
 * pattern - factory
 * **/
namespace server {

	class SubscriptionFactory {

	public:
		virtual ~SubscriptionFactory();

		/**
		 * function creates new subscription type by factory pattern
		 *
		 * ***/
		Subscription * create(const std::string&, int);
		typedef boost::shared_ptr<SubscriptionFactory> PSubscriptionFactory;

		/**
		 * returns instance of factory
		 * **/
		static PSubscriptionFactory getInstance();

	private:
		/**
		 * private constructor
		 * **/
		SubscriptionFactory();

		/**
		 * instance of factory
		 * **/
		static PSubscriptionFactory _pInstance;
	};
}


#endif /* SUBSCRIPTIONFACTORY_H_ */

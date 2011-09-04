/*
 * Subscription.h
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#ifndef SUBSCRIPTION_H_
#define SUBSCRIPTION_H_

#include "../Subject.h"
#include <string>

namespace server {

	class Subscription : public Subject{

	private:
		std::string id;

	public:
		/**
		 * Subscription objects
		 * base class
		 * **/
		Subscription();
		~Subscription();

		/**
		 * Id of specified subscription
		 * **/
		void setId(const std::string& id);

		/**
		 * return subscription id
		 * */
		const std::string& getId()const;
	};

}

#endif /* SUBSCRIPTION_H_ */

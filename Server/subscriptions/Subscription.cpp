/*
 * Subscription.cpp
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#include "Subscription.h"

namespace server {

	Subscription::Subscription() {

	}

	Subscription::~Subscription() {
	}

	void Subscription::setId(const std::string& i){
		id = i;
	}

	const std::string& Subscription::getId() const{
		return id;
	}

}

/*
 * SubscriptionFactory.cpp
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#include "SubscriptionFactory.h"
#include "Subscription.h"
#include <iostream>

namespace server {

	SubscriptionFactory::PSubscriptionFactory SubscriptionFactory::_pInstance;

	SubscriptionFactory::PSubscriptionFactory SubscriptionFactory::getInstance() {
		   if(_pInstance == NULL){
		        _pInstance = PSubscriptionFactory(new SubscriptionFactory());
		   }
		    return _pInstance;
	}

	SubscriptionFactory::SubscriptionFactory() {
	}

	SubscriptionFactory::~SubscriptionFactory() {

	}

	Subscription * SubscriptionFactory::create(const std::string& id, int type){
		Subscription * obj;
		switch(type){
		case 1:
			obj = new TimeSubscription();
			break;
		case 2:
			obj = new ProgrammerSuscription();
			break;
		case 3:
			obj = new TextSubscription();
			break;
		default:
			std::cout<<"nie ma typu";
			break;
		}
		obj->setId(id);
		return obj;
	} //create

}//namespace


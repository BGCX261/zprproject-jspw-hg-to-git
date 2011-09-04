/*
 * Subscriptions.cpp
 *
 *  Created on: Jan 17, 2011
 *      Author: asia
 */

#include "Subscriptionss.h"

namespace server {

	SubList::SubList(){}

	SubList::~SubList(){}

	SubList::PSubscriptions SubList::_pInstance;

	SubList::PSubscriptions SubList::getInstance(){
		   if(_pInstance == NULL){
			   _pInstance = SubList::PSubscriptions(new SubList());
		   }
		    return _pInstance;
	}



	void SubList::addSubscrtiption(Subscription *sub){
		_subjects.push_back(sub);
	}

	void SubList::addNewSubscription(const std::string& id, int type){
		std::list<Subscription *>::const_iterator it;
			for(it = _subjects.begin(); it != _subjects.end(); it++){
				if((*it)->getId().compare(id)==0){
					throw new std::exception();
				}
			}
			Subscription * subs = SubscriptionFactory::getInstance()->create(id, type);
			_subjects.push_back(subs);
	}

	void SubList::removeSubscription(Subscription *sub){
		_subjects.remove(sub);
	}

	Subscription* SubList::getSubscription(const std::string& name) const{
		std::list<Subscription*>::const_iterator it;
		for(it = _subjects.begin(); it != _subjects.end(); it++){
//			std::cout<<(*it)<<"\n";
			if((*it)->getId().compare(name) == 0){
				std::cout<<"znalazl subskrypcje\n";
				return *it;
			}
		}
		return NULL;
	}

	std::string SubList::toString(){
		std::string response;
		std::list<Subscription*>::const_iterator it;
		for(it = _subjects.begin(); it != _subjects.end(); it++){
			response +=(*it)->getId();
			response +="\t";
		}
		response+="\n";
		return response;
	}

	int SubList::nrOfSub(){
		_subjects.size();
	}

}

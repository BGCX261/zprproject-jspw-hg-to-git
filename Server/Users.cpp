/*
 * Users.cpp
 *
 *  Created on: Jan 17, 2011
 *      Author: asia
 */

#include "Users.h"

namespace server {

	Users::Users() {
	}

	Users::~Users() {
	}

	Users::PUsers Users::_pInstance;

	Users::PUsers Users::getInstance(){
		   if(_pInstance == NULL){
		        _pInstance = PUsers(new Users());
		   }
		    return _pInstance;
	}

	void Users::addUser(UserConnection *user){
		_users.push_back(user);
	}

	void Users::removeUser(UserConnection *user){
		_users.remove(user);
	}

	/**
	 * Searching user witch given username
	 * @return user  - if user exist, or NULL if not exist
	 * **/
	UserConnection* Users::getUser(const std::string& name) const{
		std::list<UserConnection*>::const_iterator it;
		for(it = _users.begin(); it != _users.end(); it++){
			if((*it)->getLogin().compare(name) == 0){
				return *it;
			}
		}
		return NULL;
	}

	std::list<UserConnection*> Users::getUsers() const{
		return _users;
	}

	int Users::nrOfUsers(){
		_users.size();
	}
}

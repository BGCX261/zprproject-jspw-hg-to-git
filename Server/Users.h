/*
 * Users.h
 *
 *  Created on: Jan 17, 2011
 *      Author: asia
 */

#ifndef USERS_H_
#define USERS_H_

#include <boost/shared_ptr.hpp>
#include "User.h"

#include <iostream>

namespace server {

	class Users {
	public:
		~Users();

		/**
		 * Adds user to available user list
		 * */
		void addUser(UserConnection *);

		/**
		 * Remove user from available user list
		 * */
		void removeUser(UserConnection *);

		/***
		 * Returns user with specified ids
		 * */
		UserConnection* getUser(const std::string& name) const;

		int nrOfUsers();
		typedef boost::shared_ptr<Users> PUsers;

		/*
		 * Returns instance of user list
		 * this class is a singleton
		 * **/
		static PUsers getInstance();

		/**
		 * Returns list of users
		 * **/
		std::list<UserConnection*> getUsers() const;
		;

	private:
		Users();
		static PUsers _pInstance;

		std::list<UserConnection *> _users;
	};

}

#endif /* USERS_H_ */

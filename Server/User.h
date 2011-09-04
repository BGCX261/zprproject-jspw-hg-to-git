/*
 * UserConnection.h
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#ifndef USERCONNECTION_H_
#define USERCONNECTION_H_


#include "subscriptions/Subscription.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/asio.hpp>

#include <list>
#include <map>
#include <string>

#include "Observer.h"


namespace server {

class UserConnection : public Observer{
public:
	UserConnection(const std::string& u, const std::string& c);
	UserConnection(const std::string& u, const std::string& c, boost::asio::ip::tcp::socket* );
	void update();

	~UserConnection();
    std::string getLogin() const;
    std::string getPass() const;
    void setLogin(const std::string login);
    void setPass(const std::string pass);
    boost::asio::ip::tcp::socket* getsocket();
    void addSubject(Subscription *);
    void removeSubject(Subscription *);
    bool isContainsSubject(Subscription *);
    std::list<SubscriptionLib::MsgResponse> newNews() const;
    void clear();

private:
	std::string _login;
	std::string _pass;
	boost::asio::ip::tcp::socket* _socket;
	std::map<Subscription *, int> _subjects;
	std::list<SubscriptionLib::MsgResponse> news;
	boost::mutex subjects_mutex;
	boost::mutex news_mutex;
};
}
#endif /* USERCONNECTION_H_ */

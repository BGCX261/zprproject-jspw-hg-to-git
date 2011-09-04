#include <iostream>
#include "subscriptions/SubscriptionFactory.h"
#include "User.h"
#include <vector>
#include <list>
#include "Server.h"
using namespace server;


int main(int argc, char **argv) {
	std::cout << "Synchronous TCP asio SERVER" << std::endl;

	Server::getInstance()->start();
	return 0;
}



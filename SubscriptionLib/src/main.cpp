/* 
 * File:   main.cpp
 * Author: Pawel
 *
 * Created on 8 styczeń 2011, 19:02
 */

#include <cstdlib>
#include <iostream>

#include "StringArchive.hpp"
#include "SubsRequest.hpp"
#include "Archive.hpp"

using namespace std;
using namespace SubscriptionLib;

/*
 * 
 */
int main(int argc, char** argv) {
    StringArchive sa;
    Request* req = new SubsRequest("Pawe  l", "1  1id");
    req->serialize(sa);
    cout << sa.getStr() << endl;
    getchar();
    delete req;
    auto_ptr<Request> ra = Request::deserialize(sa);
    cout << ((ra.get())->getLogin());
    //cout << (ra.get())->getLogin() << endl;
    //SubsRequest* sr = static_cast<SubsRequest*>(ra.get());
    //cout << sr->getLogin() << "\n" << sr->getSubId() << endl;
    //getchar();
    //delete sr;
    return 0;
}


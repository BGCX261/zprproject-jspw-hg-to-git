/* 
 * File:   main.cpp
 * Author: Pawel
 *
 * Created on 8 styczeń 2011, 19:02
 */

#include <cstdlib>
#include <iostream>
#include <lexical_cast.hpp>

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
    Request* req = new SubsRequest("Pawel", "id");
    req->serialize(sa);
    cout << sa.getStr() << endl;
    std::string sss = "000155";
    cout << boost::lexical_cast<int>(sss) << std::endl;
    getchar();
    delete req;
    StringArchive sb(sa.getStr());
    auto_ptr<Request> ra = Request::deserialize(sb);
    cout << ((ra.get())->getLogin());
    //cout << (ra.get())->getLogin() << endl;
    //SubsRequest* sr = static_cast<SubsRequest*>(ra.get());
    //cout << sr->getLogin() << "\n" << sr->getSubId() << endl;
    //getchar();
    //delete sr;
    return 0;
}


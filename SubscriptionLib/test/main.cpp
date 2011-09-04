/* 
 * File:   main.cpp
 * Author: Pawel
 *
 * Created on 19 styczeń 2011, 20:14
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/framework.hpp>
#include <boost/test/unit_test_suite.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>

#include "MessagesTest.hpp"

using namespace boost::unit_test;


test_suite*
init_unit_test_suite( int, char* [] ) {
    test_suite* test = BOOST_TEST_SUITE("MessagesTest");
    boost::shared_ptr<MessagesTest> instance(new MessagesTest("Login", "Id1", "Password", "Answer", "Information", 0));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::authRequest, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::authRequestSerialize, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::authResponse, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::authResponseSerialize, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::msgResponse, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::msgResponseSerialize, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::newmsgRequest, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::newmsgRequestSerialize, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::newmsgResponse, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::newmsgResponseSerialize, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::subsRequest, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::subsRequestSerialize, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::subsResponse, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::subsResponseSerialize, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::usubRequest, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::usubRequestSerialize, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::usubResponse, instance));
    test->add(BOOST_CLASS_TEST_CASE(&MessagesTest::usubResponseSerialize, instance));
    framework::master_test_suite().add(test);
    return test;
}


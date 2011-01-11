/* 
 * File:   StringArchive.cpp
 * Author: Pawel
 * 
 * Created on 8 styczeń 2011, 16:58
 */

#include <algorithm/string/classification.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>
#include <lexical_cast.hpp>

#include "StringArchive.hpp"

namespace SubscriptionLib
{
    StringArchive::StringArchive() {
    }

    StringArchive::StringArchive(const std::string& str) :
        _delimiter("\r\n") {
        boost::split(_strs, str, boost::is_any_of(_delimiter));
    }

    StringArchive::~StringArchive() {
    }

    std::string StringArchive::getStr() const {
        return boost::join(_strs, _delimiter);
    }

    Archive& StringArchive::operator <<(const std::string& str) {
        _strs.push_back(str);
    }

    Archive& StringArchive::operator >>(std::string& str) {
        str = _strs.front();
        _strs.pop_front();
    }

    Archive& StringArchive::operator <<(const int& i) {
        _strs.push_back(boost::lexical_cast<std::string>(i));
    }

    Archive& StringArchive::operator >>(int& i) {
        i = boost::lexical_cast<int>(_strs.front());
        _strs.pop_front();
    }
}


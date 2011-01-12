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
#include <iostream>
#include "StringArchive.hpp"

namespace SubscriptionLib
{
    std::string StringArchive::_delimiter = "\r\n";
    int StringArchive::_sizeLength = SIZELENGTH;

    StringArchive::StringArchive() {
    }

    StringArchive::StringArchive(const std::string& str) {
        boost::split(_strs, str, boost::is_any_of(_delimiter));
        removeEmpty(_strs);
        _strs.pop_front();
    }

    StringArchive::~StringArchive() {
    }

    std::string StringArchive::getStr() const {
         std::string res = boost::join(_strs, _delimiter);
         std::string len = boost::lexical_cast<std::string>(res.size() + _delimiter.size());
         format(len);
         return len + _delimiter + res;
    }

    int StringArchive::getSizeLength() const {
        return _sizeLength;
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

    void StringArchive::format(std::string& str) const {
        for (int i = str.size(); i < _sizeLength; ++i) {
            str = "0" + str;
        }
    }

    void StringArchive::removeEmpty(std::list<std::string>& strs) const {
        for (std::list<std::string>::iterator i = strs.begin(); i != strs.end();) {
            if (i->size() == 0)
                i = strs.erase(i);
            else
                ++i;
        }
    }
}


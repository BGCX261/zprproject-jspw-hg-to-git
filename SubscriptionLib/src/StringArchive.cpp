/* 
 * File:   StringArchive.cpp
 * Author: Pawel
 * 
 * Created on 8 styczeń 2011, 16:58
 */

#include "StringArchive.hpp"

namespace SubscriptionLib
{
    StringArchive::StringArchive() {
    }

    StringArchive::StringArchive(const std::string& str) {

    }

    std::string StringArchive::str() const {

    }

    Archive& StringArchive::operator <<(const std::string& str) {

    }

    Archive& StringArchive::operator >>(std::string& str) {

    }

    Archive& StringArchive::operator <<(const int& i) {

    }

    Archive& StringArchive::operator >>(int& i) {

    }
}


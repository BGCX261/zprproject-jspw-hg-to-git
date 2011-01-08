/* 
 * File:   Archive.hpp
 * Author: Pawel
 *
 * Created on 8 styczeń 2011, 16:56
 */

#ifndef ARCHIVE_HPP
#define	ARCHIVE_HPP

#include <string>

namespace SubscriptionLib
{
    class Archive {
    public:
        virtual std::string str() const = 0;
        virtual Archive& operator<< (const std::string& str) = 0;
        virtual Archive& operator>> (std::string& str) = 0;
        virtual Archive& operator<< (const int& i) = 0;
        virtual Archive& operator>> (int& i) = 0;
    protected:
        Archive();
    };
}
#endif	/* ARCHIVE_HPP */


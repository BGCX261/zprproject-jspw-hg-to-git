/* 
 * File:   Exception.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 21:07
 */

#ifndef EXCEPTION_HPP
#define	EXCEPTION_HPP

#include <string>
#include <exception>
#include <boost/format.hpp>

namespace SubscriptionLib
{
    class Exception : public std::exception {
    public:
        Exception();
        Exception(const std::string& str);
        Exception(const boost::format& format);
        virtual ~Exception() throw();
    private:
        std::string _str;
    };
}

#endif	/* EXCEPTION_HPP */


/* 
 * File:   Exception.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 21:07
 */

#ifndef EXCEPTION_HPP
#define	EXCEPTION_HPP

#include <string>

class Exception : public std::exception {
public:
    Exception();
    Exception(const std::string& str);
private:
    std::string _str;
};

#endif	/* EXCEPTION_HPP */


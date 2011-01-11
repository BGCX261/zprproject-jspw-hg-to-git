/* 
 * File:   Exception.hpp
 * Author: Pawel
 *
 * Created on 27 listopad 2010, 20:40
 */

#ifndef EXCEPTION_HPP
#define	EXCEPTION_HPP

#include <exception>

class Exception: public std::exception {
public:
    Exception();
    Exception(const Exception& orig);
    virtual ~Exception();

private:

};

#endif	/* EXCEPTION_HPP */


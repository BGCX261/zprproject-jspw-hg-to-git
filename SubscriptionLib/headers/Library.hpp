/* 
 * File:   Library.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 00:40
 */

#ifndef LIBRARY_HPP
#define	LIBRARY_HPP

#include "Request.hpp"
#include "Response.hpp"

class Library {
public:
    Library();
    Library(const Library& orig);
    virtual ~Library();

    bool read();
    bool write(const Request& request);
private:

};

#endif	/* LIBRARY_HPP */


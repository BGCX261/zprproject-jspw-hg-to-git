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

namespace SubscriptionLib
{
    class Library {
    public:
        Library();

        bool read();
        bool write(const Request& request);
    private:

    };
}
#endif	/* LIBRARY_HPP */


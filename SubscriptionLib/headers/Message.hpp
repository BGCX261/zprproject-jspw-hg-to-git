/* 
 * File:   Message.hpp
 * Author: Pawel
 *
 * Created on 6 styczeń 2011, 23:57
 */

#ifndef MESSAGE_HPP
#define	MESSAGE_HPP

#include <string>
#include <boost/shared_ptr.hpp>

namespace SubscriptionLib
{
    class Message {
    public:
        virtual ~Message();
    protected:
        Message();
    };
}

#endif	/* MESSAGE_HPP */


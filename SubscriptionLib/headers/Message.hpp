/* 
 * File:   Message.hpp
 * Author: Pawel
 *
 * Created on 6 styczeń 2011, 23:57
 */

#ifndef MESSAGE_HPP
#define	MESSAGE_HPP

#include <string>
#include "Visitor.hpp"

namespace SubscriptionLib
{
    class Message {
    public:
        virtual void accept(Visitor& visitor) const = 0;
    protected:
        Message();
    };
}

#endif	/* MESSAGE_HPP */


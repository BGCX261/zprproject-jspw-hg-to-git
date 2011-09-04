/* 
 * File:   Message.hpp
 * Author: Pawel
 *
 * Deklaracja klasy Message
 * Created on 6 styczeń 2011, 23:57
 */

#ifndef MESSAGE_HPP
#define	MESSAGE_HPP

#include <string>
#include <boost/shared_ptr.hpp>

namespace SubscriptionLib
{
    /*
     * Klsa bazowa dla wiadomosci
     */
    class Message {
    public:
        /*
         * Destruktor
         */
        virtual ~Message();
    protected:
        Message();
    };
}

#endif	/* MESSAGE_HPP */


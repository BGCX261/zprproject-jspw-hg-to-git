/* 
 * File:   ConditionVariable.hpp
 * Author: Pawel
 *
 * Deklaracja klasy ConditionVariable
 * Created on 1 grudzień 2010, 16:41
 */

#ifndef CONDITIONVARIABLE_HPP
#define	CONDITIONVARIABLE_HPP

#include <boost/thread/condition_variable.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

namespace Client
{
    /*
     * Proxy do zmiennej warunkowej
     */
    class ConditionVariable {
    public:
        typedef boost::shared_ptr<ConditionVariable> PCondVar;

        /*
         * Konstruktor
         */
        ConditionVariable();
        /*
         * Destruktor
         */
        virtual ~ConditionVariable();

        /*
         * Powiadomienie jednego watku oczekujacego na zmiennej warunkowej
         */
        void notify_one();
        /*
         * Oczekiwanie watku na zmiennej warunkowej
         */
        void wait();
    private:
        boost::condition_variable _condVar;
        boost::mutex _mutex;
    };
}

#endif	/* CONDITIONVARIABLE_HPP */


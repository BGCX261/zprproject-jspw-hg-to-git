/* 
 * File:   ConditionVariable.hpp
 * Author: Pawel
 *
 * Created on 1 grudzień 2010, 16:41
 */

#ifndef CONDITIONVARIABLE_HPP
#define	CONDITIONVARIABLE_HPP

#include <boost/thread/condition_variable.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

class ConditionVariable {
public:
    typedef boost::shared_ptr<ConditionVariable> PCondVar;

    ConditionVariable();
    ConditionVariable(const ConditionVariable& orig);
    virtual ~ConditionVariable();

    void notify_one();
    void wait();
private:
    boost::condition_variable _condVar;
    boost::mutex _mutex;
    //std::vector
};

#endif	/* CONDITIONVARIABLE_HPP */


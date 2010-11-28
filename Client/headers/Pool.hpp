/* 
 * File:   Pool.hpp
 * Author: Pawel
 *
 * Created on 27 listopad 2010, 21:13
 */

#ifndef POOL_HPP
#define	POOL_HPP

#include <boost/shared_ptr.hpp>

class Pool {
public:
    typedef boost::shared_ptr<Pool> PPool;

    static PPool getInstance();

    ~Pool();
    
private:
    static PPool _pInstance;

    Pool();
};

#endif	/* POOL_HPP */


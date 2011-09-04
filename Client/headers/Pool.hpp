/* 
 * File:   Pool.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klasy Pool
 * Created on 27 listopad 2010, 21:13
 */

#ifndef POOL_HPP
#define	POOL_HPP

#include "Thread.hpp"
#include "Command.hpp"
#include <boost/shared_ptr.hpp>
#include <map>

namespace Client
{
    /*
     * Odpowiedzialna za zarzadzenie watkami w aplikacji
     * Singleton
     */
    class Pool {
    public:
        typedef boost::shared_ptr<Pool> PPool;
        /*
         * Pobranie instancji
         * @return Instancja
         */
        static PPool getInstance();
        /*
         * Utworzenie nowego watku
         * @param Id watku
         */
        void createThread(int id);
        /*
         * Przekazanie komendy do watku
         * @param threadId Id watku
         * @param cmd Komena do przekazania
         */
        void passCmd(int threadId, const Command& cmd);
        /*
         * Destruktor
         */
        virtual ~Pool();

    private:
        typedef std::map<int, Thread::PThread> ThreadsSet;

        static PPool _pInstance;
        ThreadsSet _threads;

        Pool();
    };
}

#endif	/* POOL_HPP */


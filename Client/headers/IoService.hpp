/* 
 * File:   IoService.hpp
 * Author: Pawel
 *
 * Deklaracja klasy IoService
 * Created on 12 styczeń 2011, 19:49
 */

#ifndef IOSERVICE_HPP
#define	IOSERVICE_HPP

/// 1st issue
#include <boost/asio/detail/pipe_select_interrupter.hpp>

/// 2nd issue
#ifdef __CYGWIN__
#include <termios.h>
#ifdef cfgetospeed
#define __cfgetospeed__impl(tp) cfgetospeed(tp)
#undef cfgetospeed
inline speed_t cfgetospeed(const struct termios *tp)
{
	return __cfgetospeed__impl(tp);
}
#undef __cfgetospeed__impl
#endif /// cfgetospeed is a macro

/// 3rd issue
#undef __CYGWIN__
#include <boost/asio/detail/buffer_sequence_adapter.hpp>
#define __CYGWIN__
#endif


#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "ConditionVariable.hpp"

namespace Client
{
    /*
     * Proxy dla io_service
     */
    class IoService {
    public:
        typedef boost::shared_ptr<IoService> PIoService;
        /*
         * Pobranie instancji
         * @return Instancja
         */
        static PIoService getInstance();
        /*
         * Pobranie uslugi io
         * @return Usluga io
         */
        boost::asio::io_service& getService();
        /*
         * Uruchomienie uslugi (obudzenie watku)
         */
        void run();
        /*
         * Destruktor
         */
        virtual ~IoService();
    private:
        static PIoService _pInstance;
        boost::asio::io_service _service;
        boost::thread _thread;
        ConditionVariable _cond;
        IoService();
        void doRun();
    };
}

#endif	/* IOSERVICE_HPP */


/* 
 * File:   Client.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klasy Client
 * Created on 11 styczeń 2011, 13:09
 */

#ifndef CLIENT_HPP
#define	CLIENT_HPP

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


#include "lib/Request.hpp"
#include "lib/Response.hpp"
#include "lib/StringArchive.hpp"
#include "ConditionVariable.hpp"
#include <vector>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace Client
{
    /*
     * Odpowiedzialna za operacje IO z serwerem
     */
    class Client {
    public:
        typedef boost::shared_ptr<char*> PChar;
        typedef boost::shared_ptr<std::string> PString;

        /*
         * Konstruktor
         */
        Client();
        /*
         * Konstruktor
         * @param condVar Zmienna warunkowa, ktora bedzie zawiadamiana, gdy przyjdzie odpowiedz
         * @param gostIp Ip serwera
         * @param hostPort Port serwera
         */
        Client(ConditionVariable::PCondVar condVar, std::string hostIp, std::string hostPort);
        /*
         * Deksturktor
         */
        virtual ~Client();

        /*
         * Laczy z serwerem
         */
        void connect();
        /*
         * Rozlacza z serwerem
         */
        void disconnect();
        /*
         * Wysyla synchronicznie do serwera podany request
         */
        void write(SubscriptionLib::Request::PRequest req);
        /*
         * Czyta synchronicznie odpowiedz serwera
         */
        void read();
        /*
         * Czyta asynchronicznie odpowiedz serwera
         */
        void readAsynch();
        /*
         * Okresla czy jest nowa odpowiedz od serwera
         * @return Okresla czy jest nowa odpowiedz od serwera
         */
        bool isNewResponse();
        /*
         * Probuje pobrac zapisana wiadomosc od serwera
         * @param res Jesli wiadomosc istnieje to wskaznik bedzie wskazywal na nia
         * @return Okresla czy wskaznik wskazuje na nowa wiadomosc
         */
        bool tryGetResponse(SubscriptionLib::Response::PResponse& res);

        bool connected();

    private:
        std::string _hostIp;
        std::string _hostPort;
        std::string _str;
        boost::asio::ip::tcp::resolver _resolver;
        boost::asio::ip::tcp::resolver::query _query;
        boost::asio::ip::tcp::resolver::iterator _it;
        boost::asio::ip::tcp::socket _socket;
        ConditionVariable::PCondVar _pCondVar;
        std::vector<char> _bufSize;
        std::vector<char> _bufChar;
        std::vector<char> _asynBufSize;
        std::vector<char> _asynBufChar;
        SubscriptionLib::Response::PResponse _response;

        void doRead();
        void handleReadHeader(const boost::system::error_code& ec);
        void handleReadBody(const boost::system::error_code& ec);
    };
}

#endif	/* CLIENT_HPP */


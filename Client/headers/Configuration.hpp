/* 
 * File:   Configuration.hpp
 * Author: Pawel
 *
 * Deklaracja klasy Configuration
 * Created on 26 listopad 2010, 22:42
 */

#ifndef CONFIGURATION_HPP
#define	CONFIGURATION_HPP

#include <string>

namespace Client
{
    /*
     * Zawiera statyczne metody bedace konfiguracja aplikacji
     */
    class Configuration {
    public:
        /*
         * Konfiguruje aplikacje, m.in. rejestruje typy w fabryce
         * @param ip Ip serwera
         * @param port Port serwera
         */
        static void config(std::string ip, std::string port);
        /*
         * Pobiera ip hosta
         * @return Ip serwera
         */
        static std::string getIp();
        /*
         * Pobiera port hosta
         * @return Port serwera
         */
        static std::string getPort();
    private:
        static void registerCmds();
        static std::string _ip;
        static std::string _port;
    };
}

#endif	/* CONFIGURATION_HPP */


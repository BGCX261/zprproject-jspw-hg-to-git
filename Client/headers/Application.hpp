/* 
 * File:   Application.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klasy Application, bedacej klasa glowna aplikacji.
 * Created on 27 listopad 2010, 20:36
 */

#ifndef APPLICATION_HPP
#define	APPLICATION_HPP

namespace Client
{
    /*
     * Klasa glowna (startowa) aplikacji
     */
    class Application {
    public:
        /*
         * Konstruktor domyslny
         */
        Application();
        /*
         * Uruchomienie aplikacji klienckiej
         */
        void run();
    private:

    };
}

#endif	/* APPLICATION_HPP */


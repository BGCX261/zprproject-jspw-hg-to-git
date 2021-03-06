/* 
 * File:   CommandThread.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klasy CommandThread
 * Created on 30 listopad 2010, 16:00
 */

#ifndef COMMANDTHREAD_HPP
#define	COMMANDTHREAD_HPP

namespace Client
{
    /*
     * Klasa bazowa dla komend przekazywanych do watkow
     */
    class CommandThread {
    public:
        /*
         * Pobranie id watku
         * @return Id watku
         */
        int getId() const;

        /*
         * Destruktor
         */
        virtual ~CommandThread();

    protected:
        CommandThread(int threadId);
        CommandThread(const CommandThread& orig);

    private:
        int _threadId;
    };
}

#endif	/* COMMANDTHREAD_HPP */


/* 
 * File:   Queue.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klasy Queue
 * Created on 30 listopad 2010, 16:55
 */

#ifndef QUEUE_HPP
#define	QUEUE_HPP

#include "Command.hpp"
#include "Visitor.hpp"
#include "ConditionVariable.hpp"
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/shared_ptr.hpp>
#include <queue>

namespace Client
{
    /*
     * Kolejka wiadomosci miedzy watkiem klienta a watkiem glownym aplikacji
     */
    class Queue: public Visitor {
    public:
        /*
         * Konstruktor
         */
        Queue();
        /*
         * Konstruktor
         * @param generalCondVar Zmienna warunkowa, ktora bedzie informowana, gdy zostanie wstawiona nowa wiadomosc
         */
        Queue(ConditionVariable::PCondVar generalCondVar);
        /*
         * Destruktor
         */
        virtual ~Queue();
        /*
         * Wstawienie komendy do kolejki
         * @param cmd Wstawiana komenda
         */
        void push(const Command& cmd);
        /*
         * Sprawdzenie czy kolejka jest pusta
         * @return Okresla czy kolejka jest pusta
         */
        bool empty() const;
        /*
         * Pobranie komendy z kolejki
         * @param pCmd W przypadku udanego pobrania wskazuje na pobrana komende
         * @return Okredla czy pobranie wiadomosci sie udalo
         */
        bool tryPop(Command::PCommand& pCmd);
        /*
         * Ustawienie nowej zmiennej warunkowej
         * @param var Ustawiana zmienna warunkowa
         */
        void setCondVar(ConditionVariable::PCondVar var);
        /*
         * Okreslenie czy watek istnieje
         * @return Okresla czy watek istnieje
         */
        bool exists() const;

        /*
         * Ustawienie nowej wartosci dla zmiennej okreslajacej czy watek istnieje
         * @param exist Okresla czy watek istnieje
         */
        void setExists(bool exists);

        virtual void handle(const AuthCommand& );
        virtual void handle(const CreateCommand& );
        virtual void handle(const DiscCommand& );
        virtual void handle(const SubsCommand& );
        virtual void handle(const UsubCommand& );
        virtual void handle(const NewMsgCommand& );

    private:
        bool _existing;
        mutable std::queue<Command::PCommand> _queue;
        mutable boost::mutex _mutex;
        ConditionVariable::PCondVar _generalCondVar;
    };
}

#endif	/* QUEUE_HPP */


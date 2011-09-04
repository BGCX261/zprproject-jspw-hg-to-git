/* 
 * File:   Thread.hpp
 * Author: Pawel
 *
 * Deklaracja klasy Thread
 * Created on 27 listopad 2010, 21:26
 */

#ifndef THREAD_HPP
#define	THREAD_HPP

#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include "ConditionVariable.hpp"
#include "lib/ClientVisitor.hpp"
#include "lib/ServerVisitor.hpp"
#include "lib/Messages.hpp"
#include "Client.hpp"
#include "Queue.hpp"

namespace Client
{
    /*
     * Reprezentuje watek
     */
    class Thread {
    public:
        typedef boost::shared_ptr<Thread> PThread;

        /*
         * Konstuktor
         * @param id Id watku
         */
        Thread(int id);
        /*
         * Destruktor
         */
        virtual ~Thread();

        /*
         * Przeslanie do watku komendy
         * @param cmp Komenda do przeslania
         */
        void sendCmd(const Command& cmd);

        /*
         * Okreslenie czy watek nadal pracuje
         * @param Okresla czy watek pracuje
         */
        bool exists();
    private:
        typedef boost::shared_ptr<boost::thread> PBThread;

        struct Worker: public Visitor, public SubscriptionLib::ClientVisitor {
            ConditionVariable::PCondVar pCondVar;
            Queue queue;
            Client client;
            int id;

            Worker(int idThread);
            ~Worker();

            void kill();
            void run();
            void writeTerminal(const std::string& str) const;
            void writeTerminal(const boost::format& format) const;

            void handle(const AuthCommand& authCmd);
            void handle(const CreateCommand& createCmd);
            void handle(const DiscCommand& discCmd);
            void handle(const SubsCommand& subsCmd);
            void handle(const UsubCommand& usubCmd);
            void handle(const NewMsgCommand& newCmd);

            virtual void handle(const SubscriptionLib::AuthResponse& res);
            virtual void handle(const SubscriptionLib::MsgResponse& res);
            virtual void handle(const SubscriptionLib::NewMsgResponse& res);
            virtual void handle(const SubscriptionLib::SubsResponse& res);
            virtual void handle(const SubscriptionLib::UsubResponse& res);
        };

        int _id;
        Worker _worker;
        PBThread _pBThread;
    };
}



#endif	/* THREAD_HPP */


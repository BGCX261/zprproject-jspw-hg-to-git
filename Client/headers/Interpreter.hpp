/* 
 * File:   Interpreter.hpp
 * Author: Pawel
 *
 * Zawiera deklaracje klasy Interpreter
 * Created on 30 listopad 2010, 15:50
 */

#ifndef INTERPRETER_HPP
#define	INTERPRETER_HPP

#include <boost/shared_ptr.hpp>
#include "Visitor.hpp"
#include "Command.hpp"

namespace Client
{
    /*
     * Odpowiedzialna za interpretowanie komend wprowadzanych z konsoli
     * Singleton
     */
    class Interpreter : public Visitor {
    public:
        typedef boost::shared_ptr<Interpreter> PInterpreter;

        /*
         * Pobranie instancji
         * @return Instancja
         */
        static PInterpreter getInstance();
        /*
         * Destruktor
         */
        virtual ~Interpreter();

        /*
         * Obsluguje komende Auth
         * @param authCmd Komenda
         */
        void handle(const AuthCommand& authCmd);
        /*
         * Obsluguje komende Create
         * @param createCmd Komenda
         */
        void handle(const CreateCommand& createCmd);
        /*
         * Obsluguje komende Disc
         * @param discCmd Komenda
         */
        void handle(const DiscCommand& discCmd);
        /*
         * Obsluguje komende Subs
         * @param subsCmd Komenda
         */
        void handle(const SubsCommand& subsCmd);
        /*
         * Obsluguje komende Usub
         * @param usubCmd Komenda
         */
        void handle(const UsubCommand& usubCmd);
        /*
         * Obsluguje komende NewMsg
         * @param newCmd Komenda
         */
        void handle(const NewMsgCommand& newCmd);
        /*
         * Interpretuje podana komende
         * @param cmd Komenda
         */
        void interpret(const Command& cmd);

    private:
        static PInterpreter _pInstance;

        Interpreter();
    };
}

#endif	/* INTERPRETER_HPP */


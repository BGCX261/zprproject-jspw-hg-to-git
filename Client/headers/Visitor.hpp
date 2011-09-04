/* 
 * File:   Visitor.hpp
 * Author: Pawel
 *
 * Created on 30 listopad 2010, 17:30
 */

#ifndef VISITOR_HPP
#define	VISITOR_HPP

#include "AuthCommand.hpp"
#include "CreateCommand.hpp"
#include "DiscCommand.hpp"
#include "SubsCommand.hpp"
#include "UsubCommand.hpp"
#include "NewMsgCommand.hpp"

namespace Client
{
    class Visitor {
    public:
        /*
         * Destruktor
         */
        virtual ~Visitor();
        /*
         * Obsluguje komende Auth
         * @param authCmd Komenda
         */
        virtual void handle(const AuthCommand& ) = 0;
        /*
         * Obsluguje komende Create
         * @param createCmd Komenda
         */
        virtual void handle(const CreateCommand& ) = 0;
        /*
         * Obsluguje komende Disc
         * @param discCmd Komenda
         */
        virtual void handle(const DiscCommand& ) = 0;
                /*
         * Obsluguje komende Subs
         * @param subsCmd Komenda
         */
        virtual void handle(const SubsCommand& ) = 0;
        /*
         * Obsluguje komende Usub
         * @param usubCmd Komenda
         */
        virtual void handle(const UsubCommand& ) = 0;
        /*
         * Obsluguje komende NewMsg
         * @param newCmd Komenda
         */
        virtual void handle(const NewMsgCommand& ) = 0;

    protected:
        Visitor();
    };
}

#endif	/* VISITOR_HPP */


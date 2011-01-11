/* 
 * File:   Interpreter.hpp
 * Author: Pawel
 *
 * Created on 30 listopad 2010, 15:50
 */

#ifndef INTERPRETER_HPP
#define	INTERPRETER_HPP

#include <boost/shared_ptr.hpp>
#include "Visitor.hpp"
#include "Command.hpp"


class Interpreter : public Visitor {
public:
    typedef boost::shared_ptr<Interpreter> PInterpreter;

    static PInterpreter getInstance();
    virtual ~Interpreter();

    void handle(const AuthCommand& authCmd);
    void handle(const CreateCommand& createCmd);
    void handle(const DiscCommand& discCmd);
    void handle(const SubsCommand& subsCmd);
    void handle(const UsubCommand& usubCmd);
    void interpret(const Command& cmd);

private:
    static PInterpreter _pInstance;

    Interpreter();
};

#endif	/* INTERPRETER_HPP */


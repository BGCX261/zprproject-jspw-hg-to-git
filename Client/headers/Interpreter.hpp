/* 
 * File:   Interpreter.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 20:41
 */

#ifndef INTERPRETER_HPP
#define	INTERPRETER_HPP

#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include "Command.hpp"

class Interpreter {
public:
    typedef Command* (*NewCmdFun)();
    typedef boost::shared_ptr<Interpreter> PInterpreter;

    static PInterpreter getInstance();
      
    bool registerCmd(const std::string& key, NewCmdFun fun);
    Command* create (const std::string& key);

private:
    Interpreter();
    Interpreter(const Interpreter& orig);
    static PInterpreter _pInstance;

    typedef std::map<std::string, NewCmdFun> Callbacks;
    Callbacks _callbacks;
};

#endif	/* CMDFACTORY_HPP */


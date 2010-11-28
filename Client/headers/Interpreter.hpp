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
    typedef Command::PCommand (*NewCmdFun)(const std::vector<std::string>&);
    typedef boost::shared_ptr<Interpreter> PInterpreter;

    static PInterpreter getInstance();
    bool registerCmd(const std::string& key, NewCmdFun fun);
    Command::PCommand create(const std::string& key, const std::vector<std::string>& strs);
    Command::PCommand create(const std::vector<std::string>& strs);

    ~Interpreter();
    
private:
    typedef std::map<std::string, NewCmdFun> Callbacks;
    
    Callbacks _callbacks;
    static PInterpreter _pInstance;

    Interpreter();
    Interpreter(const Interpreter& orig);
    Callbacks::const_iterator find(const std::string& key);
};

#endif	/* CMDFACTORY_HPP */


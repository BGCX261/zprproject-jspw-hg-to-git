/* 
 * File:   Terminal.hpp
 * Author: Pawel
 *
 * Created on 27 listopad 2010, 20:43
 */

#ifndef TERMINAL_HPP
#define	TERMINAL_HPP

#include <boost/shared_ptr.hpp>
#include <string>
#include "Command.hpp"

class Terminal {
public:
    typedef boost::shared_ptr<Terminal> PTerminal;

    static PTerminal getInstance();
    Command::PCommand readCmd();
    std::string read();
    void write(const std::string& str);

    virtual ~Terminal();

private:
    static PTerminal _pInstance;

    Terminal();
    Terminal(const Terminal& orig);
};

#endif	/* TERMINAL_HPP */


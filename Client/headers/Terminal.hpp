/* 
 * File:   Terminal.hpp
 * Author: Pawel
 *
 * Created on 27 listopad 2010, 20:43
 */

#ifndef TERMINAL_HPP
#define	TERMINAL_HPP

#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <string>
#include "Command.hpp"

class Terminal {
public:
    typedef boost::shared_ptr<Terminal> PTerminal;

    static PTerminal getInstance();
    virtual ~Terminal();
    
    Command::PCommand readCmd();
    std::string read();
    void write(const std::string& str);

private:
    static PTerminal _pInstance;

    Terminal();

    boost::mutex _mutex;
};

#endif	/* TERMINAL_HPP */


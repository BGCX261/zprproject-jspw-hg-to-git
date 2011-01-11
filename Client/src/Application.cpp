/* 
 * File:   Application.cpp
 * Author: Pawel
 * 
 * Created on 27 listopad 2010, 20:36
 */

#include "Application.hpp"
#include "CmdFactory.hpp"
#include "Interpreter.hpp"
#include "Terminal.hpp"
#include "Command.hpp"
#include "Pool.hpp"

#include <iostream>
Application::Application() {
}

void Application::run() {
    Terminal::PTerminal terminal = Terminal::getInstance();
    Command::PCommand command;
    Interpreter::PInterpreter interpreter = Interpreter::getInstance();
    while(1) {
        command = terminal->readCmd();
        interpreter->interpret(*command);
    }
    
}

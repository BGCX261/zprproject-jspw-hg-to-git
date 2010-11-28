/* 
 * File:   Application.cpp
 * Author: Pawel
 * 
 * Created on 27 listopad 2010, 20:36
 */

#include "Application.hpp"
#include "Interpreter.hpp"
#include "Terminal.hpp"

Application::Application() {
    
}

void Application::run() {
    Terminal::PTerminal terminal = Terminal::getInstance();
    while(1) {
        terminal->readCmd();
    }
    
}

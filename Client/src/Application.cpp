/* 
 * File:   Application.cpp
 * Author: Pawel
 *
 * Implementacja klasy Application
 * Created on 27 listopad 2010, 20:36
 */

#include <boost/format.hpp>
#include "Application.hpp"
#include "CmdFactory.hpp"
#include "Interpreter.hpp"
#include "Terminal.hpp"
#include "Command.hpp"
#include "Pool.hpp"
#include "ExceptionClient.hpp"

namespace Client
{
    Application::Application() {
    }

    void Application::run() {
        Terminal::PTerminal terminal = Terminal::getInstance();
        Command::PCommand command;
        Interpreter::PInterpreter interpreter = Interpreter::getInstance();
        while(1) {
            try
            {
                command = terminal->readCmd();
                interpreter->interpret(*command);
            }
            catch (ExceptionClient e)
            {
                Terminal::getInstance()->write(boost::format("Error received: %1%\n") %e.what());
            }
            catch (std::exception e)
            {
                Terminal::getInstance()->write(boost::format("Error received: %1%\n") %e.what());
            }
        }
    }
}

/* 
 * File:   main.cpp
 * Author: Pawel
 *
 * Created on 14 październik 2010, 19:44
 */

#include <cstdlib>
#include <Configuration.hpp>
#include <Interpreter.hpp>
#include <Command.hpp>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Configuration::config();
    Interpreter::PInterpreter pi = Interpreter::getInstance();
    delete (pi->create("auth"));
    delete (pi->create("subs"));
    return 0;
}


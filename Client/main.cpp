/* 
 * File:   main.cpp
 * Author: Pawel
 *
 * Created on 14 październik 2010, 19:44
 */

#include <cstdlib>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "Application.hpp"
#include "Configuration.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Configuration::config();
    Application app;
    app.run();
    
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Pawel
 *
 * Funkcja main
 * Created on 14 październik 2010, 19:44
 */

#include <cstdlib>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include "Application.hpp"
#include "Configuration.hpp"

#include "lib/Id.hpp"

using namespace std;
using namespace Client;

int main(int argc, char** argv) {

    Configuration::config(boost::lexical_cast<string>(argv[1]), boost::lexical_cast<string>(argv[2]));
    Application app;
    app.run();
    
    return 0;
}


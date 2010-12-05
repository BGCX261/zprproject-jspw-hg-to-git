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
    /*std::string str;
    std::getline(std::cin, str);
    boost::trim(str);
    std::vector<std::string> strs;
    boost::split(strs, str, boost::is_any_of("\t "));
    std::vector<std::string> copy(strs);
    copy.erase(copy.begin());
    for (int i = 0; i < copy.size(); ++i)
        std::cout << copy[i] << std::endl;
     */
    
    Configuration::config();
    Application app;
    app.run();
    
    return 0;
}


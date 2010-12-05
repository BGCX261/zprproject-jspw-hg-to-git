/* 
 * File:   Terminal.cpp
 * Author: Pawel
 * 
 * Created on 27 listopad 2010, 20:43
 */

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "Terminal.hpp"
#include "CmdFactory.hpp"

Terminal::PTerminal Terminal::_pInstance;

Terminal::Terminal() {
}

Terminal::Terminal(const Terminal& orig) {
}

Terminal::~Terminal() {
}

Terminal::PTerminal Terminal::getInstance() {
    if(_pInstance.get() == NULL)
        _pInstance = PTerminal(new Terminal);
    return _pInstance;
}

Command::PCommand Terminal::readCmd() {
    std::string data = read();
    std::vector<std::string> strs;
    boost::split(strs, data, boost::is_any_of("\t "));
    //if wyjscie z klienta
    return CmdFactory::getInstance()->create(strs);
}

std::string Terminal::read() {
    //write("\n\x3E\x3E\x3E");
    std::string str;
    std::getline(std::cin, str);
    boost::trim(str);
    return str;
}

void Terminal::write(const std::string& str) {
    boost::mutex::scoped_lock lock(_mutex);
    std::cout << str;
}

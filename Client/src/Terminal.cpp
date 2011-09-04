/* 
 * File:   Terminal.cpp
 * Author: Pawel
 *
 * Implementacja klasy Terminal
 * Created on 27 listopad 2010, 20:43
 */

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "Terminal.hpp"
#include "CmdFactory.hpp"

namespace Client
{
    Terminal::PTerminal Terminal::_pInstance;

    Terminal::Terminal() {
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
        return CmdFactory::getInstance()->create(strs);
    }

    std::string Terminal::read() {
        std::string str;
        std::getline(std::cin, str);
        boost::trim(str);
        return str;
    }

    void Terminal::write(const std::string& str) {
        boost::mutex::scoped_lock lock(_mutex);
        std::cout << str;
    }

    void Terminal::write(const boost::format& format) {
        write(format.str());
    }
}

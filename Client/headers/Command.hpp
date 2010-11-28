/* 
 * File:   Command.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:15
 */

#ifndef COMMAND_HPP
#define	COMMAND_HPP

#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>



class Command {
public:
    typedef boost::shared_ptr<Command> PCommand;
    static PCommand create(const std::vector<std::string>& strs);
private:

};

#endif	/* COMMAND_HPP */


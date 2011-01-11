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

class Visitor;

class Command {
public:
    typedef boost::shared_ptr<Command> PCommand;

    virtual ~Command();

    static PCommand create(const std::vector<std::string>& strs);

    virtual void accept(const Visitor& visitor) const = 0;
protected:
    Command();
};

#endif	/* COMMAND_HPP */


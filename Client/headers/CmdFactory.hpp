/* 
 * File:   CmdFactory.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 20:41
 */

#ifndef CMDFACTORY_HPP
#define	CMDFACTORY_HPP

#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include "Command.hpp"

class CmdFactory {
public:
    typedef Command::PCommand (*NewCmdFun)(const std::vector<std::string>&);
    typedef boost::shared_ptr<CmdFactory> PCmdFactory;

    static PCmdFactory getInstance();
    bool registerCmd(const std::string& key, NewCmdFun fun);
    Command::PCommand create(const std::string& key, const std::vector<std::string>& strs);
    Command::PCommand create(const std::vector<std::string>& strs);

    ~CmdFactory();
    
private:
    typedef std::map<std::string, NewCmdFun> Callbacks;
    
    Callbacks _callbacks;
    static PCmdFactory _pInstance;

    CmdFactory();
    CmdFactory(const CmdFactory& orig);
    Callbacks::const_iterator find(const std::string& key);
};

#endif	/* CMDFACTORY_HPP */


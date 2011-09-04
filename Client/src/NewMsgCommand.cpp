/* 
 * File:   NewMsgCommand.cpp
 * Author: Pawel
 *
 * Implementacja klasy NewMsgCommand
 * Created on 11 styczeń 2011, 20:12
 */

#include <boost/algorithm/string/join.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include "Visitor.hpp"
#include "NewMsgCommand.hpp"
#include "ExceptionClient.hpp"

namespace Client
{
    NewMsgCommand::NewMsgCommand(std::string login, std::string type, std::string message, int threadId) :
        CommandThread(threadId), _login(login), _type(type), _msg(message) {
    }

    NewMsgCommand::NewMsgCommand(const NewMsgCommand& orig) :
        CommandThread(orig), _login(orig._login), _type(orig._type), _msg(orig._msg) {
    }

    NewMsgCommand::~NewMsgCommand() {
    }

    NewMsgCommand::PCommand NewMsgCommand::create(const std::vector<std::string>& strs) {
        if (strs.size() < 4)
            throw ExceptionClient("NewMsgCommand create: wrong number of parameters, expected 4.");
        std::vector<std::string> str(strs);
        str.erase(str.begin(), str.begin() + 3);
        return PCommand(new NewMsgCommand(strs[1], strs[2], boost::join(str, " "), boost::lexical_cast<int>(strs[0])));
    }

    void NewMsgCommand::accept(Visitor& visitor) const {
        visitor.handle(*this);
    }

    std::string NewMsgCommand::getLogin() const {
        return _login;
    }

    std::string NewMsgCommand::getType() const {
        return _type;
    }

    std::string NewMsgCommand::getMsg() const {
        return _msg;
    }
}


/* 
 * File:   UsubCommand.cpp
 * Author: Pawel
 *
 * Implementacja klasy UsubCommand
 * Created on 26 listopad 2010, 14:19
 */

#include "UsubCommand.hpp"
#include "Visitor.hpp"
#include "ExceptionClient.hpp"
#include <boost/lexical_cast.hpp>

namespace Client
{
    UsubCommand::UsubCommand(std::string login, std::string type, int threadId) :
        CommandThread(threadId), _login(login), _type(type) {
    }

    UsubCommand::UsubCommand(const UsubCommand& orig) :
        CommandThread(orig), _login(orig._login), _type(orig._type) {
    }

    UsubCommand::~UsubCommand() {
    }

    UsubCommand::PCommand UsubCommand::create(const std::vector<std::string>& strs) {
        if (strs.size() != 3)
            throw ExceptionClient("UsubCommand create: wrong number of parameters, expected 3.");
        return PCommand(new UsubCommand(strs[1], strs[2], boost::lexical_cast<int>(strs[0])));
    }

    void UsubCommand::accept(Visitor& visitor) const {
        visitor.handle(*this);
    }

    std::string UsubCommand::getLogin() const {
        return _login;
    }

    std::string UsubCommand::getType() const {
        return _type;
    }
}
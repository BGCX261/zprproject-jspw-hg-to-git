/* 
 * File:   Visitor.hpp
 * Author: Pawel
 *
 * Created on 30 listopad 2010, 17:30
 */

#ifndef VISITOR_HPP
#define	VISITOR_HPP

#include "AuthCommand.hpp"
#include "CreateCommand.hpp"
#include "DiscCommand.hpp"
#include "SubsCommand.hpp"
#include "UsubCommand.hpp"

class Visitor {
public:

    virtual void handle(const AuthCommand& ) const = 0;
    virtual void handle(const CreateCommand& ) const = 0;
    virtual void handle(const DiscCommand& ) const = 0;
    virtual void handle(const SubsCommand& ) const = 0;
    virtual void handle(const UsubCommand& ) const = 0;

protected:
    Visitor();
};

#endif	/* VISITOR_HPP */


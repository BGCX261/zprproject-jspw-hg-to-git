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
    virtual ~Visitor();
    virtual void handle(const AuthCommand& ) = 0;
    virtual void handle(const CreateCommand& ) = 0;
    virtual void handle(const DiscCommand& ) = 0;
    virtual void handle(const SubsCommand& ) = 0;
    virtual void handle(const UsubCommand& ) = 0;

protected:
    Visitor();
};

#endif	/* VISITOR_HPP */


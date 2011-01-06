/* 
 * File:   Serializeable.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 00:08
 */

#ifndef SERIALIZEABLE_HPP
#define	SERIALIZEABLE_HPP

#include <map>

template<class Type, class Base>
struct Creator
{
    static Base* Create();
};

template<class Type>
struct ClassId
{
    static std::string Id();
};

template<class Type>
class Serializeable {
public:
    virtual ~Serializeable();

    typedef Type*(*CreateFun)();
    typedef std::map<std::string, CreateFun> Register;

    virtual std::string id() = 0;
    virtual std::string serialize() = 0;
    virtual void deserialize() = 0;
protected:
    Serializeable();

private:
};

#endif	/* SERIALIZEABLE_HPP */


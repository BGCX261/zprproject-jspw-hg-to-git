/* 
 * File:   Serializeable.hpp
 * Author: Pawel
 *
 * Created on 7 styczeń 2011, 00:08
 */

#ifndef SERIALIZEABLE_HPP
#define	SERIALIZEABLE_HPP

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>
#include "Archive.hpp"
#include <memory>

template<class TType, class TBase>
struct Creator
{
    static TBase* create();
};

template<class TType>
struct ClassId
{
    static std::string id();
};

template<class TType>
class Serializeable {
public:
    virtual ~Serializeable();

    typedef TType*(*CreateFun)();
    typedef std::map<std::string, CreateFun> Register;

    void serialize(Archive& archive) const;
    static std::auto_ptr<TType> deserialize(Archive& archive);

    static bool registerCreator(std::string id, CreateFun createFun);

protected:
    virtual std::string id() const = 0;
    virtual bool doSerialize(Archive& archive) const = 0;
    virtual bool doDeserialize(Archive& archive) = 0;

private:
    static Register& getRegister();
};

template<class TType, class TBase>
class RegisterSerializeable
{
public:
    RegisterSerializeable();
    static bool isRegistered;
};

#include "Serializeable_impl.hpp"

#endif	/* SERIALIZEABLE_HPP */


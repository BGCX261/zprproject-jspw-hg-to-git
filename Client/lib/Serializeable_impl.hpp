/* 
 * File:   Serializeable_impl.hpp
 * Author: Pawel
 *
 * Implementacja funkcji serializujacych
 * Created on 7 styczeń 2011, 20:53
 */

#ifndef SERIALIZEABLE_IMPL_HPP
#define	SERIALIZEABLE_IMPL_HPP

#include "Serializeable.hpp"
#include "ExceptionLib.hpp"
#include <boost/format.hpp>
#include <iostream>
#include <string>

namespace SubscriptionLib
{
    template<class TType, class TBase>
    TBase* Creator<TType, TBase>::create() {
        return new TType();
    }

    template<class TType>
    Serializeable<TType>::~Serializeable() {

    }

    template<class TType>
    void Serializeable<TType>::serialize(Archive& archive) const {
        archive << this->id();
        this->doSerialize(archive);
    }

    template<class TType>
    std::auto_ptr<TType> Serializeable<TType>::deserialize(Archive& archive) {
        Register& creators = getRegister();
        std::string id;
        archive >> id;
        typename Register::const_iterator i = creators.find(id);
        if(i == creators.end())
            throw new Exception((boost::format("Unknown message id %1%") % id).str());
        std::auto_ptr<TType> result((*i->second)());
        static_cast<Serializeable<TType>*>(result.get())->doDeserialize(archive);
        return result;
    }

    template<class TType>
    bool Serializeable<TType>::registerCreator(std::string id, CreateFun createFun) {
        Register& creators = getRegister();
        assert(creators.find(id) == creators.end());
        creators[id] = createFun;
        return true;
    }

    template<class TType>
    typename Serializeable<TType>::Register& Serializeable<TType>::getRegister() {
        static Register creatorFuns;
        return creatorFuns;
    }

    template<class TType, class TBase>
    RegisterSerializeable<TType, TBase>::RegisterSerializeable() {
        assert(isRegistered);
        isRegistered;
    }

    template<class TType, class TBase>
    bool RegisterSerializeable<TType, TBase>::isRegistered =
        Serializeable<TBase>::registerCreator(
            ClassId<TType>::id(),
            Creator<TType, TBase>::create
        );
}

#endif	/* SERIALIZEABLE_IMPL_HPP */


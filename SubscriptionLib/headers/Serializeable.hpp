/* 
 * File:   Serializeable.hpp
 * Author: Pawel
 *
 * Deklaracja klas umozliowiajacych serializacje wiadomosci
 * Created on 7 styczeń 2011, 00:08
 */

#ifndef SERIALIZEABLE_HPP
#define	SERIALIZEABLE_HPP

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>
#include "Archive.hpp"
#include <memory>

namespace SubscriptionLib
{
    /*
     * Szablon klsy bedacej tworca serializowanych obiektow
     */
    template<class TType, class TBase>
    struct Creator
    {
        static TBase* create();
    };

    /*
     * Id serializowanej klasy
     */
    template<class TType>
    struct ClassId
    {
        static std::string id();
    };

    /*
     * Szablon zawierajacy metody serializacji
     */
    template<class TType>
    class Serializeable {
    public:
        /*
         * Destruktor
         */
        virtual ~Serializeable();

        typedef TType*(*CreateFun)();
        typedef std::map<std::string, CreateFun> Register;

        /*
         * Serializacja
         * @param archive Archiwum, do ktorego ma byc wiadomosc zserailizowana
         */
        void serialize(Archive& archive) const;
        /*
         * Deserializacja
         * @param archive Archiwum, z ktorego wiadomosc ma byc deserializowana
         * @retun Wskaznik na zdeserializowana wiadomosc
         */
        static std::auto_ptr<TType> deserialize(Archive& archive);

        /*
         * Rejestracja nowego typu serializowanej wiadomosci
         * @param id Id klasy
         * @param createFun Funkcja tworzaca obiekt wiadomosci
         * @return Okresla czy udalo sie zrejestrowac klase
         */
        static bool registerCreator(std::string id, CreateFun createFun);

    protected:
        virtual std::string id() const = 0;
        virtual bool doSerialize(Archive& archive) const = 0;
        virtual bool doDeserialize(Archive& archive) = 0;

    private:
        static Register& getRegister();
    };

    /*
     * wzorzec CRTP do serializacji wiadomosci
     */
    template<class TType, class TBase>
    class RegisterSerializeable
    {
    public:
        RegisterSerializeable();
        static bool isRegistered;
    };
}

#include "Serializeable_impl.hpp"

#endif	/* SERIALIZEABLE_HPP */


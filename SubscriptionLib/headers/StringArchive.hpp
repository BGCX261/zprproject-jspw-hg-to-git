/* 
 * File:   StringArchive.hpp
 * Author: Pawel
 *
 * Created on 8 styczeń 2011, 16:58
 */

#ifndef STRINGARCHIVE_HPP
#define	STRINGARCHIVE_HPP

#include "Archive.hpp"

class StringArchive: public Archive {
public:
    StringArchive();
    StringArchive(const std::string& str);
    virtual std::string str() const;
    virtual Archive& operator<< (const std::string& str);
    virtual Archive& operator>> (std::string& str);
    virtual Archive& operator<< (const int& i);
    virtual Archive& operator>> (int& i);
private:
    
};

#endif	/* STRINGARCHIVE_HPP */


/* 
 * File:   AuthCommand.hpp
 * Author: Pawel
 *
 * Created on 26 listopad 2010, 14:16
 */

#ifndef AUTHCOMMAND_HPP
#define	AUTHCOMMAND_HPP

class AuthCommand: public Command {
public:
    AuthCommand();
    AuthCommand(const AuthCommand& orig);
    virtual ~AuthCommand();
    
    virtual static Command* create();
private:

};

#endif	/* AUTHCOMMAND_HPP */


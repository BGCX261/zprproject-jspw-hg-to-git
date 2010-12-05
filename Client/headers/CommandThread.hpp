/* 
 * File:   CommandThread.hpp
 * Author: Pawel
 *
 * Created on 30 listopad 2010, 16:00
 */

#ifndef COMMANDTHREAD_HPP
#define	COMMANDTHREAD_HPP

class CommandThread {
public:
    CommandThread(int threadId);
    CommandThread(const CommandThread& orig);
    virtual ~CommandThread();

    int getId() const;
private:
    int _threadId;
};

#endif	/* COMMANDTHREAD_HPP */


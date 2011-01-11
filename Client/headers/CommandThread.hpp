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
    int getId() const;

    virtual ~CommandThread();

protected:
    CommandThread(int threadId);
    CommandThread(const CommandThread& orig);

private:
    int _threadId;
};

#endif	/* COMMANDTHREAD_HPP */


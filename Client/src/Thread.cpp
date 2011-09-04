/* 
 * File:   Thread.cpp
 * Author: Pawel
 *
 * Implementacja klasy Thread
 * Created on 27 listopad 2010, 21:26
 */

#include "Thread.hpp"
#include "Terminal.hpp"
#include "Configuration.hpp"
#include "ExceptionClient.hpp"

namespace Client
{
    Thread::Thread(int id) :
        _id(id), _worker(id), _pBThread(new boost::thread(&Worker::run, &_worker))  {
    }

    Thread::~Thread() {
    }

    bool Thread::exists() {
        return _worker.queue.exists();
    }

    void Thread::sendCmd(const Command& cmd) {
        if (_worker.queue.exists())
            _worker.queue.push(cmd);
        else
            throw ExceptionClient(boost::format("Worker %1% has been terminated") %_id);
    }

    Thread::Worker::Worker(int idThread) :
        pCondVar(new ConditionVariable()), queue(pCondVar), client(pCondVar, Configuration::getIp(),
            Configuration::getPort()), id(idThread) {
        queue.setExists(true);
    }

    Thread::Worker::~Worker() {
    }

    void Thread::Worker::run() {
        writeTerminal("run");
        Command::PCommand pCmd;
        SubscriptionLib::Response::PResponse pRes;
        while(1) {
            writeTerminal("waiting");
            try
            {
                if (queue.empty() && !client.isNewResponse()) {
                    pCondVar->wait();
                }
                if (queue.tryPop(pCmd)) {
                    pCmd->accept(*this);
                }
                else if (client.tryGetResponse(pRes)) {
                    pRes->accept(*this);
                }
            }
            catch (ExceptionClient e)
            {
                writeTerminal(boost::format("Error received: %1%\n Terminate worker") %e.what());
                kill();
                return;
            }
            catch (std::exception e)
            {
                writeTerminal(boost::format("Error received: %1%\n Terminate worker") %e.what());
                kill();
                return;
            }
        }
    }

    void Thread::Worker::kill() {
        queue.setExists(false);
    }

    void Thread::Worker::handle(const AuthCommand& authCmd) {
        if (!client.connected())
            client.connect();
        writeTerminal("connected");
        client.write(SubscriptionLib::Request::PRequest(new SubscriptionLib::AuthRequest(authCmd.getLogin(), authCmd.getPasswd())));
        client.read();
    }

    void Thread::Worker::handle(const CreateCommand& createCmd) {
        writeTerminal("unhandled create commad");
    }

    void Thread::Worker::handle(const DiscCommand& discCmd) {
        client.disconnect();
    }

    void Thread::Worker::handle(const SubsCommand& subsCmd) {
        client.write(SubscriptionLib::Request::PRequest(new SubscriptionLib::SubsRequest(subsCmd.getLogin(), subsCmd.getType())));
        client.read();
        //client.readAsynch();
    }

    void Thread::Worker::handle(const UsubCommand& usubCmd) {
        client.write(SubscriptionLib::Request::PRequest(new SubscriptionLib::UsubRequest(usubCmd.getLogin(), usubCmd.getType())));
        client.read();
    }

    void Thread::Worker::handle(const NewMsgCommand& newCmd) {
        client.write(SubscriptionLib::Request::PRequest(new SubscriptionLib::NewMsgRequest(newCmd.getLogin(), newCmd.getType(), newCmd.getMsg())));
        client.read();
    }

    void Thread::Worker::handle(const SubscriptionLib::AuthResponse& res) {
        writeTerminal(boost::format("Received auth response:\nStatus: %1%,\nAnswer: %2%")
                %res.getStatus() %res.getAnswer());
    }

    void Thread::Worker::handle(const SubscriptionLib::MsgResponse& res) {
        writeTerminal((boost::format("Received new message:\nStatus: %1%,\nAnswer: %2%,\nSubId: %3%,\nMsg: %4%")
                % res.getStatus() % res.getAnswer() % res.getSubId() % res.getInfo()));
        client.readAsynch();
    }

    void Thread::Worker::handle(const SubscriptionLib::NewMsgResponse& res) {
        writeTerminal(boost::format("Received new message response:\nStatus: %1%,\nAnswer: %2%")
                %res.getStatus() %res.getAnswer());
    }

    void Thread::Worker::handle(const SubscriptionLib::SubsResponse& res) {
        writeTerminal(boost::format("Received subscription response:\nStatus: %1%,\nAnswer: %2%")
                %res.getStatus() %res.getAnswer());
        client.readAsynch();
    }

    void Thread::Worker::handle(const SubscriptionLib::UsubResponse& res) {
        writeTerminal(boost::format("Received unsubscription response:\nStatus: %1%,\nAnswer: %2%")
                %res.getStatus() %res.getAnswer());
    }

    void Thread::Worker::writeTerminal(const std::string& str) const {
        writeTerminal(boost::format(str));
    }

    void Thread::Worker::writeTerminal(const boost::format& format) const {
        Terminal::getInstance()->write(boost::format("Worker %1%: %2%.\n") %id %format);
    }
}
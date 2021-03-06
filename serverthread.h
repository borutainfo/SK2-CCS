#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <config.h>

class ServerThread : public QThread {
    Q_OBJECT

public:
    void run();
    ~ServerThread();
    void stop();
    void refreshStatus();
    QString getList();
    void sendInfo();

signals:
    void serverStatus(int clients, int consultants);
    void serverAction(QString);
    void serverError(QString);
    void serverStarted();

private:
    int addUser(user);
    void removeUser(int);
    void removeUser(int, bool);
    int server_port = 6666;
    int sock, buf_size = 0, clients = 0, consultants = 0, newID = 0, optval = 1;
    char buf[2048];
    struct sockaddr_in server;
    socklen_t size = sizeof(struct sockaddr);
    std::vector <user> users;
    QString send;
    user temp;

};

#endif // SERVERTHREAD_H

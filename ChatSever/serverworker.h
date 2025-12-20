#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QObject>
#include <QTcpSocket>
class ServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit ServerWorker(QObject *parent = nullptr);
    virtual bool setSocktetDescriptor(qintptr socketDescriptor);

signals:

private:
    QTcpSocket *m_serverSocket;
};

#endif // SERVERWORKER_H

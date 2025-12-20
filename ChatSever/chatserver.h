#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <serverworker.h>
class ChatServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ChatServer(QObject *parent=nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void logMessage(const QString &msg);

public slots:
    void stopServer();
    QVector<ServerWorker*> m_clients;
};

#endif // CHATSERVER_H

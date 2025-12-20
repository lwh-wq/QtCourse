#include "serverworker.h"



ServerWorker::ServerWorker(QObject *parent)
{
    m_serverSocket=new QTcpSocket(this);
}

bool ServerWorker::setSocktetDescriptor(qintptr socketDescriptor)
{
    return m_serverSocket->setSocketDescriptor(socketDescriptor);
}

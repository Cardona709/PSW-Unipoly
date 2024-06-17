#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include <vector>
#include <string>
#include "gameinit_client.h"

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);


signals:

public slots:
    void connectToServer(const QString name, const QString &ip, const QString &port);
    void sendMessage(const QString &message);
    void disconnect();
    void setgame(GameInit_Client *game);
    void sendDiceRoll();
    void sendEndTurn();
    void sendBuyProperty();
    void sendChance();
    void sendCommunity();
    void sendPayBill();
    void senDouble();


private slots:
    void onConnected();
    void onReadyRead();
    void onErrorOccurred(QAbstractSocket::SocketError error);
    void onDisconnected();




private:
    QTcpSocket _socket;
    GameInit_Client *_game;
};

#endif // TCPCLIENT_HPP

#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <QObject>
#include <QTcpServer>
#include <QHash>
#include <QTcpSocket>
#include <QNetworkInterface>
#include "gameinit.h"

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);
    int maxplayers;


signals:
    void newMessage(const QByteArray &ba);
    void canStart();
    void deletePlayer3();
    void deletePlayer4();


public slots:
    void launchServer(int n, QString name);
    void sendMessage(const QString &message);
    void closeserver();
    void set_game(GameLogic *game);
    void sendStart();
    void sendNextPlayer();
    void actions(int code);
    void updateplayers_money();
    void updateplayers_position();
    void sendChangePropOwner(int pos, std::string name);
    void changePropOwner();



private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();
    void onNewMessage(const QByteArray &ba);
    void onCanStart();
    void onDeletePlayer3();
    void onDeletePlayer4();


private:
    QString getClientKey(const QTcpSocket *client) const;
private:
    QTcpServer _server;
    QHash<QString, QTcpSocket*> _clients;
    GameLogic *_game;
    //vector of gamelogic objects
    std::vector<GameLogic> info;
};

#endif // TCPSERVER_HPP

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "TcpClient.hpp"
#include "TcpServer.hpp"
#include "gameinit.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl viewer(u"qrc:/QT_Unipoly/viewer.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    TcpServer tcpServer;
    TcpClient client;
    GameLogic *game = new GameLogic();
    GameInit_Client *game_client = new GameInit_Client();
    //setting game to receive infos from server
    tcpServer.set_game(game);
    //setting game to receive infos from client
    client.setgame(game_client);


    engine.rootContext()->setContextProperty("server", &tcpServer);
    engine.rootContext()->setContextProperty("client", &client);
    engine.rootContext()->setContextProperty("game", game);
    engine.rootContext()->setContextProperty("game_client", game_client);


    engine.load(viewer);

    return app.exec();
}

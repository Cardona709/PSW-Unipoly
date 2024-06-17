cmake_minimum_required(VERSION 3.16)

project(QT_Unipoly VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appQT_Unipoly
    gameUI.cpp
)

qt_add_qml_module(appQT_Unipoly
    URI QT_Unipoly
    VERSION 1.0
    QML_FILES viewer.qml

    RESOURCES
    assets/images/aboutlogo.png
    assets/images/back_button.png
    assets/images/bengala.png
    assets/images/colher.png
    assets/images/dice.png
    assets/images/gandafino.png
    assets/images/hostlogo.png
    assets/images/instructionslogo.png
    assets/images/joinlogo.png
    assets/images/top_hat.png
    assets/images/unipoly_logo.png
    assets/images/volumelogo.png
    assets/images/selector_arrow.png
    assets/images/monopoly_map.png
    assets/images/back_arrow.png
    assets/images/volume_disabled.png
    assets/images/settings_icon.png
    assets/images/praxislogo.png

    assets/fonts/KabelBdNormal.ttf
    assets/fonts/KabelMedium.ttf

    assets/audio/menumusic.mp3

    QML_FILES aboutPage.qml
    QML_FILES instructionsPage.qml
    QML_FILES hostGame.qml
    QML_FILES joinGame.qml
    QML_FILES lobbyMenu_host.qml
    QML_FILES gameMap_host.qml
    QML_FILES mainMenu.qml
    QML_FILES lobbyMenu_client.qml
    QML_FILES gameMap_client.qml

    SOURCES TcpServer.cpp TcpServer.hpp
    SOURCES TcpClient.cpp TcpClient.hpp
    SOURCES gameinit.h gameinit.cpp
    SOURCES gameinit_client.h gameinit_client.cpp
    SOURCES logic/Board.cpp logic/Cards.cpp logic/Dice.cpp logic/Faculty.cpp logic/Game.cpp logic/Player.cpp logic/Property.cpp logic/Station.cpp logic/Utility.cpp
    SOURCES include/logic/Board.h include/logic/Cards.h include/logic/Dice.h include/logic/Faculty.h include/logic/Game.h include/logic/Player.h include/logic/Property.h include/logic/Server.h include/logic/Station.h include/logic/Utility.h
    QML_FILES splash.qml

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQT_Unipoly PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQT_Unipoly
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQT_Unipoly
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appQT_Unipoly
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

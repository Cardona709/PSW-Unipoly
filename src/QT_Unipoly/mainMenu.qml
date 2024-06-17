import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import QtMultimedia

Item {

    FontLoader {
        id: boldfont
        source: "assets/fonts/KabelBdNormal.ttf"
    }

    FontLoader {
        id: mediumfont
        source: "assets/fonts/KabelMedium.ttf"
    }

    //background with 1280x720 and light blue color

    Rectangle {

        id: windowBackground
        width: 1280
        height: 720

        color: "#9DC3E6"

        Rectangle{

            id: buttonBackground
            width: parent.width/1.2
            height: parent.height/2.5
            y: parent.height/2.5
            border.width: 10
            border.color: "#203864"
            radius: 30
            color: "#8FAADC"

            anchors.horizontalCenter: parent.horizontalCenter

            RoundButton {
                id: hostButton
                contentItem: Text {
                    text: qsTr("Host Game")
                    font.family: boldfont.name
                    font.pixelSize: 22
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }

                height: parent.height/1.5
                width: parent.width/4.5
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: (parent.width - 4*width)/5
                radius: 30

                background: Rectangle{
                    color: "white"
                    border.width: 3
                    border.color: "#203864"
                    radius: parent.radius
                }

                Image {
                    id: hostlogo
                    source: "assets/images/hostlogo.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 3
                    width:200; height: 145
                    fillMode:Image.PreserveAspectFit; clip: true;
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked:
                    {
                        myStack.push("hostGame.qml")
                    }
                }
            }

            RoundButton {
                id: joinButton
                contentItem: Text {
                    text: qsTr("Join Game")
                    font.family: boldfont.name
                    font.pixelSize: 22
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }

                height: parent.height/1.5
                width: parent.width/4.5
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 2*(parent.width - 4*width)/5 + width
                radius: 30

                background: Rectangle{
                    color: "white"
                    border.width: 3
                    border.color: "#203864"
                    radius: parent.radius
                }

                Image {
                    id: joinlogo
                    source: "assets/images/joinlogo.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 15
                    width:400; height: 130
                    fillMode:Image.PreserveAspectFit; clip: true;
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked:
                    {
                        myStack.push("joinGame.qml");
                    }
                }
            }

            RoundButton {
                id: instructionsButton
                contentItem: Text {
                    text: qsTr("Instructions")
                    font.family: boldfont.name
                    font.pixelSize: 22
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    anchors.top: parent.top
                    anchors.topMargin: 10
                }

                height: parent.height/1.5
                width: parent.width/4.5
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 2*(parent.width - 4*width)/5 + width
                radius: 30

                background: Rectangle{
                    color: "white"
                    border.width: 3
                    border.color: "#203864"
                    radius: parent.radius
                }

                Image {
                    id: instructionslogo
                    source: "assets/images/instructionslogo.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 15
                    width:400; height: 140
                    fillMode:Image.PreserveAspectFit; clip: true;
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked:
                    {
                        myStack.push("instructionsPage.qml")
                    }
                }
            }

            RoundButton {
                id: aboutButton
                contentItem: Text {
                    text: qsTr("About Us")
                    font.family: boldfont.name
                    font.pixelSize: 22
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    anchors.top: parent.top
                    anchors.topMargin: 10


                }

                height: parent.height/1.5
                width: parent.width/4.5
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: (parent.width - 4*width)/5
                radius: 30

                background: Rectangle{
                    color: "white"
                    border.width: 3
                    border.color: "#203864"
                    radius: parent.radius
                }
                Image {
                    id: aboutlogo
                    source: "assets/images/aboutlogo.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 25
                    width:400; height: 120
                    fillMode:Image.PreserveAspectFit; clip: true;
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked:
                    {
                        myStack.push("aboutPage.qml")
                    }
                }
            }
        }

        Glow {
                anchors.fill: buttonBackground
                radius: 25
                samples: 100
                color: "#203864"
                smooth: true
                source: buttonBackground
        }

        Image {
            id: mainlogo
            source: "assets/images/unipoly_logo.png"
            anchors.horizontalCenter: parent.horizontalCenter
            width:400; height: 360
            fillMode:Image.PreserveAspectFit; clip: true;
        }

        Glow {
                anchors.fill: mainlogo
                radius: 25
                samples: 100
                color: "#203864"
                smooth: true
                source: mainlogo
        }

        Image {
            id: settingslogo
            source: "assets/images/settings_icon.png"
            anchors.verticalCenter: quitButton.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: parent.width/30
            mipmap: true
            width:70; height: 70
            fillMode:Image.PreserveAspectFit; clip: true;
            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked:
                {
                    myStack.push(settingsPage)
                }
            }
        }


        RoundButton {
            id: quitButton
            contentItem: Text {
                text: qsTr("Quit")
                font.family: boldfont.name
                font.pixelSize: 22
                color: "black"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            width: parent.width/6
            height: parent.height/12

            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height/20
            anchors.right: parent.right
            anchors.rightMargin: parent.width/20

            radius: 20

            font.family: boldfont.name
            font.pixelSize: 22

            background: Rectangle{
                color: "white"
                border.width: 3
                border.color: "#203864"
                radius: parent.radius
            }


            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: Qt.quit()
            }

        }
    }

}

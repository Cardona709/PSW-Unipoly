import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt5Compat.GraphicalEffects
import QtQuick.Controls.Material


Item{

    FontLoader {
        id: boldfont
        source: "assets/fonts/KabelBdNormal.ttf"
    }

    FontLoader {
        id: mediumfont
        source: "assets/fonts/KabelMedium.ttf"
    }

    Rectangle {

        id: windowBackground
        width: 1280
        height: 720

        color: "#9DC3E6"

        //create 3 second timer
        Timer {
            id: timer
            interval: 3000; running: true; repeat: false
            onTriggered: {
                myStack.replace("mainMenu.qml")
            }
        }

        Image {
            id: mainlogo
            source: "assets/images/unipoly_logo.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.verticalCenter
            anchors.bottomMargin: -100
            width:400; height: 400
            fillMode:Image.PreserveAspectFit; clip: true;
        }

        Text {
            id: splashText
            text: "WELCOME TO UNIPOLY, THE CLASSIC \nUNIVERSITARY BOARD GAME!"
            horizontalAlignment: Text.AlignHCenter
            font.family: boldfont.name
            font.pixelSize: 30
            color: "#203864"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: mainlogo.bottom
            anchors.topMargin: -50
        }

        Glow {
                anchors.fill: mainlogo
                radius: 25
                samples: 100
                color: "#203864"
                smooth: true
                source: mainlogo
        }
    }
}

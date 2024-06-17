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

    //background with 1280x720 and light blue color

    Rectangle {

        id: windowBackground
        width: 1280
        height: 720

        color: "#9DC3E6"

        Rectangle{
            id: buttonBackground
            width: parent.width/1.2
            height: parent.height/2
            y: parent.height/3.1
            border.width: 5
            border.color: "#203864"
            radius: 30
            color: "#DEEBF7"

            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: authors
                text: qsTr("Game made by:\n\nCarina Silva\nDiogo Ferreira\nGonçalo Cardoso\nGonçalo Pereira")
                font.family: boldfont.name
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 40
                font.pixelSize: 22
                color: "#203864"
             }

            Text {
                id: context
                text: qsTr("This game was developed as part of the final project for the Software Design course, Master in Electrical and\nComputer Engineering, FEUP 2023/24.")
                font.family: mediumfont.name
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: authors.bottom
                anchors.topMargin: 35
                font.pixelSize: 20
                color: "#203864"
             }

            Text {
                id: credits
                text: qsTr("All rights go to Hasbro and Monopoly brand.")
                font.family: mediumfont.name
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                font.pixelSize: 18
                color: "#203864"
             }
        }


        Image {
            id: mainlogo
            source: "assets/images/unipoly_logo.png"
            anchors.horizontalCenter: parent.horizontalCenter
            width:300; height: 300
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
            id: returnlogo
            source: "assets/images/back_button.png"
            anchors.top: parent.top
            anchors.topMargin: parent.height/40
            anchors.left: parent.left
            anchors.leftMargin: parent.width/50
            width:100; height: 100
            fillMode:Image.PreserveAspectFit; clip: true;

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    myStack.pop()
                }
                cursorShape: Qt.PointingHandCursor
            }
        }

        Glow {
                anchors.fill: returnlogo
                radius: 20
                samples: 100
                color: "#203864"
                smooth: true
                source: returnlogo
        }
    }
}

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
                id: title
                text: qsTr("Instructions")
                font.family: boldfont.name
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 40
                font.pixelSize: 22
                color: "#203864"
             }

            Text {
                id: maintext
                text: qsTr("Introducing Unipoly, a captivating adaptation of the classic game.\n
    In this version, players will embark on an academic adventure, just as they would in the original game.\n
    The objective remains consistent: to establish a thriving academic real estate empire around Porto\n
    faculties and outmaneuver fellow players.\n\n\n\nAnd remember, HAVE FUN!\n\n\n\nDISCLAIMER: We do not take responsability for broken friendships.\n\n\n\n")
                font.family: mediumfont.name
                lineHeight: 0.7
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: title.bottom
                anchors.topMargin: 25
                font.pixelSize: 18
                color: "#203864"
             }

            Text {
                id: link_Text
                text: 'For a complete ruleset of the original game go to <html><style type="text/css"></style><a href="https://www.hasbro.com/common/instruct/00009.pdf">Hasbro Instructions</a></html>'
                font.family: mediumfont.name
                lineHeight: 0.7
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 25
                font.pixelSize: 18
                color: "#203864"

                Rectangle {
                    id: link
                    anchors.right: parent.right
                    width: parent.width/3.5
                    height: parent.height
                    color: "transparent"
                    MouseArea {
                        onClicked: Qt.openUrlExternally("https://www.hasbro.com/common/instruct/00009.pdf")
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                    }
                }
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

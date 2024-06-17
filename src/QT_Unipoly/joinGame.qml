import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt5Compat.GraphicalEffects
import QtQuick.Controls.Material


Item{

    Connections {
            target: client

    }

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
            height: parent.height/2.5
            y: parent.height/3.1
            border.width: 5
            border.color: "#203864"
            radius: 30
            color: "#DEEBF7"

            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: nameLabel
                text: qsTr("Enter your nickname:")
                font.family: boldfont.name
                horizontalAlignment: Text.AlignHCenter
                anchors.top: parent.top
                anchors.topMargin: 80
                anchors.left: parent.left
                anchors.leftMargin: 30
                font.pixelSize: 22
                color: "#203864"
            }

            TextField {
                id: nickInput
                anchors.left: nameLabel.right
                anchors.leftMargin: 30
                anchors.top: nameLabel.top
                anchors.topMargin: -20
                font.pixelSize: 30
                font.family: boldfont.name
                selectionColor: "#203864"
                color: "#203864"
                focus: true
                maximumLength: 12
                height: 70
                width: 350

                background: Rectangle {
                    color: "white"
                    border.width: 3
                    width: parent.width*1.2
                    height: parent.height
                    anchors.bottom: parent.top
                    anchors.bottomMargin: -70
                    anchors.left: parent.left
                    anchors.leftMargin: -5
                    border.color: "#203864"
                    radius: 20
                }
                cursorDelegate: Rectangle {
                        id: cursor
                        visible: false
                        color: "#203864"
                        width: nickInput.cursorRectangle.width*3

                        SequentialAnimation {
                            loops: Animation.Infinite
                            running: nickInput.cursorVisible

                            PropertyAction {
                                target: cursor
                                property: 'visible'
                                value: true
                            }

                            PauseAnimation {
                                duration: 600
                            }

                            PropertyAction {
                                target: cursor
                                property: 'visible'
                                value: false
                            }

                            PauseAnimation {
                                duration: 600
                            }

                            onStopped: {
                                cursor.visible = false
                            }
                        }
                }
            }

            Text {
                id: inviteLabel
                text: qsTr("Invitation link:")
                font.family: boldfont.name
                horizontalAlignment: Text.AlignHCenter
                anchors.top: nameLabel.bottom
                anchors.topMargin: parent.height/4
                anchors.left: parent.left
                anchors.leftMargin: 30
                font.pixelSize: 22
                color: "#203864"
            }

            TextField {
                id: inviteInput
                text: "127.0.0.1"
                anchors.left: inviteLabel.right
                anchors.leftMargin: 30
                anchors.top: inviteLabel.top
                anchors.topMargin: -20
                font.pixelSize: 30
                font.family: boldfont.name
                color: "#203864"
                focus: true
                maximumLength: 12
                height: 70
                width: 250
                background: Rectangle {
                    color: "white"
                    border.width: 3
                    width: parent.width*1.2
                    height: parent.height
                    anchors.bottom: parent.top
                    anchors.bottomMargin: -70
                    anchors.left: parent.left
                    anchors.leftMargin: -5
                    border.color: "#203864"
                    radius: 20
                }

                cursorDelegate: Rectangle {
                        id: cursor2
                        visible: false
                        color: "#203864"
                        width: inviteInput.cursorRectangle.width*3

                        SequentialAnimation {
                            loops: Animation.Infinite
                            running: inviteInput.cursorVisible

                            PropertyAction {
                                target: cursor2
                                property: 'visible'
                                value: true
                            }

                            PauseAnimation {
                                duration: 600
                            }

                            PropertyAction {
                                target: cursor2
                                property: 'visible'
                                value: false
                            }

                            PauseAnimation {
                                duration: 600
                            }

                            onStopped: {
                                cursor2.visible = false
                            }
                        }
                }
            }

        }

        RoundButton {
            id: join
            contentItem: Text {
                text: qsTr("Join Game")
                font.family: boldfont.name
                font.pixelSize: 22
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            width: parent.width/6
            height: parent.height/10

            anchors.verticalCenter: buttonBackground.bottom
            anchors.right: buttonBackground.right
            anchors.rightMargin: buttonBackground.width/20

            radius: 20

            font.family: boldfont.name
            font.pixelSize: 22

            background: Rectangle{
                color: "#E44C35"
                border.width: 3
                border.color: "#C00000"
                radius: parent.radius
            }
            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked:
                {
                    myStack.push("lobbyMenu_client.qml")
                    client.connectToServer(nickInput.text,inviteInput.text, 12345)
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

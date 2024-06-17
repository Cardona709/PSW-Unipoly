import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt5Compat.GraphicalEffects
import QtQuick.Controls.Material


Item{

    Connections{
        target: server
        function onCanStart(){
             start.enabled = true

        }
        function onDeletePlayer3(){
            player3Model.visible = false
            player3Name.visible =false
            player3SelectorL.visible = false
            player3SelectorR.visible = false
        }
        function onDeletePlayer4(){
            player4Model.visible = false
            player4Name.visible =false
            player4SelectorL.visible = false
            player4SelectorR.visible = false
        }

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
            width: parent.width/1.15
            height: parent.height/2.3
            y: parent.height/2.7
            border.width: 7
            border.color: "#203864"
            radius: 35
            color: "#DEEBF7"

            anchors.horizontalCenter: parent.horizontalCenter

            property var img_arr: ["assets/images/top_hat.png", "assets/images/bengala.png", "assets/images/gandafino.png", "assets/images/colher.png"]

            Text {
                id: maintext
                text: qsTr(" ")
                font.family: mediumfont.name
                lineHeight: 0.7
                horizontalAlignment: Text.AlignHCenter
                anchors.verticalCenter: parent.vericalCenter
                font.pixelSize: 18
                color: "#203864"
             }

            Image {
                id: player1Model
                source: parent.img_arr[0]
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: -parent.height/8
                anchors.right: player1SelectorR.left
                anchors.rightMargin: 6
                width: parent.width/8; height: parent.width/8
                fillMode:Image.PreserveAspectFit; clip: true;
                property int player1Counter: 0
            }

            Image {
                id: player1SelectorL
                source: "assets/images/selector_arrow.png"
                anchors.verticalCenter: player1Model.verticalCenter
                anchors.right: player1Model.left
                anchors.rightMargin: 6
                width: parent.width/22; height: parent.width/22
                fillMode:Image.PreserveAspectFit; clip: true;
                mirror: true
                visible: false

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(player1Model.player1Counter == 0){
                            player1Model.player1Counter = 3
                        }
                        else{
                            player1Model.player1Counter--
                        }
                        player1Model.source = buttonBackground.img_arr[player1Model.player1Counter]
                    }
                }
            }

            Image {
                id: player1SelectorR
                source: "assets/images/selector_arrow.png"
                anchors.verticalCenter: player1Model.verticalCenter
                anchors.right: player2SelectorL.left
                anchors.rightMargin: 12
                width: parent.width/22; height: parent.width/22
                fillMode:Image.PreserveAspectFit; clip: true;
                visible: false

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(player1Model.player1Counter == 3){
                            player1Model.player1Counter = 0
                        }
                        else{
                            player1Model.player1Counter++
                        }
                        player1Model.source = buttonBackground.img_arr[player1Model.player1Counter]
                    }
                }
            }

            Rectangle {
                id: player1Name
                width: parent.width/6
                height: parent.height/8
                anchors.top: player1Model.bottom
                anchors.topMargin: parent.height/16
                anchors.horizontalCenter: player1Model.horizontalCenter
                color: "transparent"
                border.width: 3
                border.color: "#0070C0"
                radius: 10
                Text {
                    text: qsTr("Player1")
                    font.family: boldfont.name
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    color: "#203864"

                }
            }

            Image {
                id: player2Model
                source: "assets/images/bengala.png"
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: -parent.height/8
                anchors.right: player2SelectorR.left
                anchors.rightMargin: 6
                width: parent.width/8; height: parent.width/8
                fillMode:Image.PreserveAspectFit; clip: true;
                visible: true;

                property int player2Counter: 1
            }

            Image {
                id: player2SelectorL
                source: "assets/images/selector_arrow.png"
                anchors.verticalCenter: player2Model.verticalCenter
                anchors.right: player2Model.left
                anchors.rightMargin: 6
                width: parent.width/22; height: parent.width/22
                fillMode:Image.PreserveAspectFit; clip: true;
                mirror: true
                visible: false

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(player2Model.player2Counter == 0){
                            player2Model.player2Counter = 3
                        }
                        else{
                            player2Model.player2Counter--
                        }
                        player2Model.source = buttonBackground.img_arr[player2Model.player2Counter]
                    }
                }
            }

            Image {
                id: player2SelectorR
                source: "assets/images/selector_arrow.png"
                anchors.verticalCenter: player2Model.verticalCenter
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 6
                width: parent.width/22; height: parent.width/22
                fillMode:Image.PreserveAspectFit; clip: true;
                visible: false

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(player2Model.player2Counter == 3){
                            player2Model.player2Counter = 0
                        }
                        else{
                            player2Model.player2Counter++
                        }
                        player2Model.source = buttonBackground.img_arr[player2Model.player2Counter]
                    }
                }
            }

            Rectangle {
                id: player2Name
                width: parent.width/6
                height: parent.height/8
                anchors.top: player2Model.bottom
                anchors.topMargin: parent.height/16
                anchors.horizontalCenter: player2Model.horizontalCenter
                color: "transparent"
                border.width: 3
                border.color: "#FFFF00"
                radius: 10
                Text {
                    text: qsTr("Player2")
                    font.family: boldfont.name
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    color: "#203864"

                }
            }

            Image {
                id: player3Model
                source: "assets/images/gandafino.png"
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: -parent.height/8
                anchors.left: player3SelectorL.right
                anchors.leftMargin: 6
                width: parent.width/8; height: parent.width/8
                fillMode:Image.PreserveAspectFit; clip: true;

                property int player3Counter: 2
            }

            Image {
                id: player3SelectorL
                source: "assets/images/selector_arrow.png"
                anchors.verticalCenter: player3Model.verticalCenter
                anchors.left: parent.horizontalCenter
                anchors.leftMargin: 6
                width: parent.width/22; height: parent.width/22
                fillMode:Image.PreserveAspectFit; clip: true;
                mirror: true
                visible: false

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(player3Model.player3Counter == 0){
                            player3Model.player3Counter = 3
                        }
                        else{
                            player3Model.player3Counter--
                        }
                        player3Model.source = buttonBackground.img_arr[player3Model.player3Counter]
                    }
                }
            }

            Image {
                id: player3SelectorR
                source: "assets/images/selector_arrow.png"
                anchors.verticalCenter: player3Model.verticalCenter
                anchors.left: player3Model.right
                anchors.leftMargin: 6
                width: parent.width/22; height: parent.width/22
                fillMode:Image.PreserveAspectFit; clip: true;
                visible: false

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(player3Model.player3Counter == 3){
                            player3Model.player3Counter = 0
                        }
                        else{
                            player3Model.player3Counter++
                        }
                        player3Model.source = buttonBackground.img_arr[player3Model.player3Counter]
                    }
                }
            }

            Rectangle {
                id: player3Name
                width: parent.width/6
                height: parent.height/8
                anchors.top: player3Model.bottom
                anchors.topMargin: parent.height/16
                anchors.horizontalCenter: player3Model.horizontalCenter
                color: "transparent"
                border.width: 3
                border.color: "#548235"
                radius: 10
                Text {
                    text: qsTr("Player3")
                    font.family: boldfont.name
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    color: "#203864"

                }
            }

            Image {
                id: player4Model
                source: "assets/images/colher.png"
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: -parent.height/8
                anchors.left: player4SelectorL.right
                anchors.leftMargin: 6
                width: parent.width/8; height: parent.width/8
                fillMode:Image.PreserveAspectFit; clip: true;

                property int player4Counter: 3
            }

            Image {
                id: player4SelectorL
                source: "assets/images/selector_arrow.png"
                anchors.verticalCenter: player4Model.verticalCenter
                anchors.left: player3SelectorR.right
                anchors.leftMargin: 12
                width: parent.width/22; height: parent.width/22
                fillMode:Image.PreserveAspectFit; clip: true;
                mirror: true

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(player4Model.player4Counter == 0){
                            player4Model.player4Counter = 3
                        }
                        else{
                            player4Model.player4Counter--
                        }
                        player4Model.source = buttonBackground.img_arr[player4Model.player4Counter]
                    }
                }
            }

            Image {
                id: player4SelectorR
                source: "assets/images/selector_arrow.png"
                anchors.verticalCenter: player4Model.verticalCenter
                anchors.left: player4Model.right
                anchors.leftMargin: 6
                width: parent.width/22; height: parent.width/22
                fillMode:Image.PreserveAspectFit; clip: true;

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(player4Model.player4Counter == 3){
                            player4Model.player4Counter = 0
                        }
                        else{
                            player4Model.player4Counter++
                        }
                        player4Model.source = buttonBackground.img_arr[player4Model.player4Counter]
                    }
                }
            }

            Rectangle {
                id: player4Name
                width: parent.width/6
                height: parent.height/8
                anchors.top: player4Model.bottom
                anchors.topMargin: parent.height/16
                anchors.horizontalCenter: player4Model.horizontalCenter
                color: "transparent"
                border.width: 3
                border.color: "#BC0000"
                radius: 10
                Text {
                    text: qsTr("Player4")
                    font.family: boldfont.name
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    color: "#203864"

                }
            }
        }

        Rectangle{
            id: inviteBox1
            width: parent.width/3
            height: parent.height/9
            border.width: 4
            border.color: "#203864"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height/30
            anchors.left: parent.left
            anchors.leftMargin: parent.width/20
            radius: 30
            color: "#DEEBF7"

            Text {
                id: inviteLink
                text: qsTr("127.0.0.1")
                font.family: boldfont.name
                horizontalAlignment: Text.AlignHCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: parent.width/8
                font.pixelSize: 27
                color: "#203864"
             }
        }

        Rectangle{
            id: inviteBox2
            width: inviteBox1.width/2.2
            height: inviteBox1.height
            border.width: 4
            border.color: "#203864"
            anchors.left: inviteBox1.left
            anchors.verticalCenter: inviteBox1.verticalCenter
            radius: 30
            color: "#2F5597"

            Text {
                id: inviteText
                text: qsTr("Invite Link:")
                font.family: boldfont.name
                horizontalAlignment: Text.AlignHCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.left: parent.left
                anchors.leftMargin: parent.width/10
                font.pixelSize: 24
                color: "white"
             }
        }

        RoundButton {
            id: start
            contentItem: Text {
                text: qsTr("Start")
                font.family: boldfont.name
                font.pixelSize: 28
                color: enabled ? "white" : "#7F7F7F"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            width: parent.width/8
            height: parent.height/10
            anchors.verticalCenter: buttonBackground.bottom
            anchors.right: buttonBackground.right
            anchors.rightMargin: buttonBackground.width/20

            radius: 20
            enabled: false

            font.family: boldfont.name
            font.pixelSize: 22

            background: Rectangle{
                color: parent.enabled? "#E44C35" : "#D9D9D9"
                border.width: 3
                border.color: parent.enabled? "#C00000" : "#A6A6A6"
                radius: parent.radius
            }
            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked:
                {
                    myStack.push("gameMap_host.qml")
                    game.startGame()
                    server.sendStart()
                }
            }
        }

        Image {
            id: mainlogo
            source: "assets/images/unipoly_logo.png"
            anchors.horizontalCenter: parent.horizontalCenter
            width:350; height: 350
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
                    myStack.pop();
                    client.disconnect()
                    server.closeserver()
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

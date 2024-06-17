import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt5Compat.GraphicalEffects
import QtQuick.Controls.Material


Item{
    Connections{
        target: game
        function onNextPlayerDisable(){
            playerDice.enabled = false
            playerManage.enabled = false
            playerCheck.enabled = false
            opponent1Trade.enabled = false
            opponent1Check.enabled = false
            opponent2Trade.enabled = false
            opponent2Check.enabled = false
            opponent3Trade.enabled = false
            opponent3Check.enabled = false
        }
        function onMyTurn(){
            playerDice.enabled = true
            playerManage.enabled = true
            playerCheck.enabled = true
            opponent1Trade.enabled = true
            opponent1Check.enabled = true
            opponent2Trade.enabled = true
            opponent2Check.enabled = true
            opponent3Trade.enabled = true
            opponent3Check.enabled = true
        }
        function onDeleteGPlayer3(){
            opponent2Banner.visible = false
            opponent2Ball.visible = false
            opponent2Icon.visible = false
        }
        function onDeleteGPlayer4(){
            opponent3Banner.visible = false
            opponent3Ball.visible = false
            opponent3Icon.visible = false
        }
        function onUpdatePlayerCredits(){
            playerCredits.text = "ECTS: " + game.getPlayerCredits(0)
            opponent1Credits.text = "ECTS: " + game.getPlayerCredits(1)
            if(game.get_number_of_players()>2){
                opponent2Credits.text = "ECTS: " + game.getPlayerCredits(2)
            }
            if(game.get_number_of_players()>3){
                opponent3Credits.text = "ECTS: " + game.getPlayerCredits(3)
            }
        }
        function onUpdatePlayerPosition(){
            if (game.getPlayerPosition(0) >= 0 && game.getPlayerPosition(0) < 10)
            {
                playerBall.x = map.bottom_row_positions[game.getPlayerPosition(0)]
                playerBall.y = 635
            }

            else if (game.getPlayerPosition(0) >= 10 && game.getPlayerPosition(0) < 20)
            {
                playerBall.x = 15
                playerBall.y = map.left_column_positions[game.getPlayerPosition(0)-10]
            }

            else if (game.getPlayerPosition(0) >= 20 && game.getPlayerPosition(0) < 30)
            {
                playerBall.x = map.top_row_positions[game.getPlayerPosition(0)-20]
                playerBall.y = 15
            }

            else if (game.getPlayerPosition(0) >= 30 && game.getPlayerPosition(0) < 40)
            {
                playerBall.x = 635
                playerBall.y = map.right_column_positions[game.getPlayerPosition(0)-30]
            }

            if (game.getPlayerPosition(1) >= 0 && game.getPlayerPosition(1) < 10)
            {
                opponent1Ball.x = map.bottom_row_positions[game.getPlayerPosition(1)] + playerBall.width + 5
                opponent1Ball.y = 635
            }

            else if (game.getPlayerPosition(1) >= 10 && game.getPlayerPosition(1) < 20)
            {
                opponent1Ball.x = 15 + playerBall.width + 5
                opponent1Ball.y = map.left_column_positions[game.getPlayerPosition(1)-10]
            }

            else if (game.getPlayerPosition(1) >= 20 && game.getPlayerPosition(1) < 30)
            {
                opponent1Ball.x = map.top_row_positions[game.getPlayerPosition(1)-20] + playerBall.width + 5
                opponent1Ball.y = 15
            }

            else if (game.getPlayerPosition(1) >= 30 && game.getPlayerPosition(1) < 40)
            {
                opponent1Ball.x = 635 + playerBall.width + 5
                opponent1Ball.y = map.right_column_positions[game.getPlayerPosition(1)-30]
            }

            if(game.get_number_of_players()>2){
                if (game.getPlayerPosition(2) >= 0 && game.getPlayerPosition(2) < 10)
                {
                    opponent2Ball.x = map.bottom_row_positions[game.getPlayerPosition(2)]
                    opponent2Ball.y = 635 + playerBall.height + 5
                }

                else if (game.getPlayerPosition(2) >= 10 && game.getPlayerPosition(2) < 20)
                {
                    opponent2Ball.x = 15
                    opponent2Ball.y = map.left_column_positions[game.getPlayerPosition(2)-10] + playerBall.height + 5
                }

                else if (game.getPlayerPosition(2) >= 20 && game.getPlayerPosition(2) < 30)
                {
                    opponent2Ball.x = map.top_row_positions[game.getPlayerPosition(2)-20]
                    opponent2Ball.y = 15 + playerBall.height + 5
                }

                else if (game.getPlayerPosition(2) >= 30 && game.getPlayerPosition(2) < 40)
                {
                    opponent2Ball.x = 635
                    opponent2Ball.y = map.right_column_positions[game.getPlayerPosition(2)-30] + playerBall.height + 5
                }
            }

            if(game.get_number_of_players()>3){
                if (game.getPlayerPosition(3) >= 0 && game.getPlayerPosition(3) < 10)
                {
                    opponent3Ball.x = map.bottom_row_positions[game.getPlayerPosition(3)] + playerBall.width + 5
                    opponent3Ball.y = 635 + playerBall.height + 5
                }

                else if (game.getPlayerPosition(3) >= 10 && game.getPlayerPosition(3) < 20)
                {
                    opponent3Ball.x = 15 + playerBall.width + 5
                    opponent3Ball.y = map.left_column_positions[game.getPlayerPosition(3)-10] + playerBall.height + 5
                }

                else if (game.getPlayerPosition(3) >= 20 && game.getPlayerPosition(3) < 30)
                {
                    opponent3Ball.x = map.top_row_positions[game.getPlayerPosition(3)-20] + playerBall.width + 5
                    opponent3Ball.y = 15 + playerBall.height + 5
                }

                else if (game.getPlayerPosition(3) >= 30 && game.getPlayerPosition(3) < 40)
                {
                    opponent3Ball.x = 635 + playerBall.width + 5
                    opponent3Ball.y = map.right_column_positions[game.getPlayerPosition(3)-30] + playerBall.height + 5
                }
            }

        }
        function onUpdateProperty(property_name, color, rent, name){
            var i=0
            if(name===game.getPlayerName(0)){
                manageModel.append({propName: property_name, propRent: rent, propColor: color})
                unmortgageProperty.enabled = true
                for(i = 0; i < opponent1List.count; i++){
                    if(opponent1List.get(i).propName===property_name){
                       opponent1List.remove(i)
                        i=0
                    }
                }
                for(i = 0; i < opponent2List.count; i++){
                    if(opponent2List.get(i).propName===property_name){
                       opponent2List.remove(i)
                        i=0
                    }
                }
                for(i = 0; i < opponent3List.count; i++){
                    if(opponent3List.get(i).propName===property_name){
                       opponent3List.remove(i)
                        i=0
                    }
                }
            }
            else if(name===game.getPlayerName(1)){
                opponent1List.append({propName: property_name, propRent: rent, propColor: color})

                for(i=0; i<manageModel.count; i++){
                    if(manageModel.get(i).propName===property_name){
                        manageModel.remove(i)
                        i=0
                    }
                }
                for(i = 0; i < opponent2List.count; i++){
                    if(opponent2List.get(i).propName===property_name){
                       opponent2List.remove(i)
                        i=0
                    }
                }
                for(i = 0; i < opponent3List.count; i++){
                    if(opponent3List.get(i).propName===property_name){
                       opponent3List.remove(i)
                        i=0
                    }
                }

            }
            else if(name===game.getPlayerName(2)){
                opponent2List.append({propName: property_name, propRent: rent, propColor: color})

                for(i=0; i<manageModel.count; i++){
                    if(manageModel.get(i).propName===property_name){
                        manageModel.remove(i)
                        i=0
                    }
                }
                for(i = 0; i < opponent1List.count; i++){
                    if(opponent1List.get(i).propName===property_name){
                       opponent1List.remove(i)
                        i=0
                    }
                }
                for(i = 0; i < opponent3List.count; i++){
                    if(opponent3List.get(i).propName===property_name){
                       opponent3List.remove(i)
                        i=0
                    }
                }
            }
            else if(name===game.getPlayerName(3)){
                opponent3List.append({propName: property_name, propRent: rent, propColor: color})

                for(i=0; i<manageModel.count; i++){
                    if(manageModel.get(i).propName===property_name){
                        manageModel.remove(i)
                        i=0
                    }
                }
                for(i = 0; i < opponent1List.count; i++){
                    if(opponent1List.get(i).propName===property_name){
                       opponent1List.remove(i)
                        i=0
                    }
                }
                for(i = 0; i < opponent2List.count; i++){
                    if(opponent2List.get(i).propName===property_name){
                       opponent2List.remove(i)
                        i=0
                    }
                }
            }

        }
        function onUpdatePlayerName(){
            playerName.text = game.getPlayerName(0)
            opponent1Name.text = game.getPlayerName(1)
            if(game.get_number_of_players()>2){
                opponent2Name.text = game.getPlayerName(2)
            }
            if(game.get_number_of_players()>3){
                opponent3Name.text = game.getPlayerName(3)
            }
        }

        function onChanceCommunityCard(consequence){
            popupBackground.visible = true
            communityChanceBox.visible = true
            communityChanceText.text = consequence
        }
        function onInJail(){
            jailOptions.visible = true
            popupBackground.visible = true
            if(game.get_current_balance()>50){
                payBailButton.enabled = true
            }
            else{
                payBailButton.enabled = false
            }
            useCardButton.enabled = false
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

        Image {
            id: map
            source: "assets/images/monopoly_map.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            height: parent.height*0.97
            width: height
            mipmap: true

            property var bottom_row_positions : [635, 550, 494, 438, 382, 326, 269, 213, 157, 100, 15]
            property var left_column_positions : [635, 550, 494, 438, 382, 326, 269, 213, 157, 100, 15]
            property var top_row_positions : [15, 100, 157, 213, 269, 326, 382, 438, 494, 550, 635]
            property var right_column_positions : [15, 100, 157, 213, 269, 326, 382, 438, 494, 550, 635]

            Rectangle{
                id: playerBall
                width: parent.width/32
                height: parent.height/32
                radius: 0.5 * width
                border.color: "#1F4E79"
                border.width: 2
                color: "#B4C7E7"
                x: 635
                y: 635
            }

            Image{
                id: playerIcon
                source: "assets/images/top_hat.png"
                width: playerBall.width/1.4
                height: playerBall.height/1.4
                mipmap: true
                anchors.centerIn: playerBall
            }

            Rectangle{
                id: opponent1Ball
                width: parent.width/32
                height: parent.height/32
                radius: 0.5 * width
                border.color: "#BF9000"
                border.width: 2
                color: "#FFF2CC"
                x: 635 + playerBall.width + 5
                y: 635
            }

            Image{
                id: opponent1Icon
                source: "assets/images/bengala.png"
                width: opponent1Ball.width/1.4
                height: opponent1Ball.height/1.4
                mipmap: true
                anchors.centerIn: opponent1Ball
            }

            Rectangle{
                id: opponent2Ball
                width: parent.width/32
                height: parent.height/32
                radius: 0.5 * width
                border.color: "#385723"
                border.width: 2
                color: "#E2F0D9"
                x: 635
                y: 635 + playerBall.height + 5
            }

            Image{
                id: opponent2Icon
                source: "assets/images/gandafino.png"
                width: opponent2Ball.width/1.4
                height: opponent2Ball.height/1.4
                mipmap: true
                anchors.centerIn: opponent2Ball
            }

            Rectangle{
                id: opponent3Ball
                width: parent.width/32
                height: parent.height/32
                radius: 0.5 * width
                border.color: "#C00000"
                border.width: 2
                color: "#F8CBAD"
                x: 635 + playerBall.width + 5
                y: 635 + playerBall.height + 5
            }

            Image{
                id: opponent3Icon
                source: "assets/images/colher.png"
                width: opponent3Ball.width/1.4
                height: opponent3Ball.height/1.4
                mipmap: true
                anchors.centerIn: opponent3Ball
            }
        }

        Image {
            id: watermark

            anchors.bottom: settingslogo.top
            anchors.left: parent.left
            anchors.bottomMargin: 5
            anchors.leftMargin: 50
            opacity: 0.35
            height: 150
            fillMode:Image.PreserveAspectFit; clip: true;

            source: "assets/images/unipoly_logo.png"

        }

        Image {
            id: settingslogo
            source: "assets/images/settings_icon.png"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: watermark.horizontalCenter
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

        Rectangle{
            id: playerBanner
            width: parent.width/5.2
            height: parent.height/1.6
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 20
            anchors.leftMargin: 20
            border.width: 5
            border.color: "#1F4E79"
            radius: 30
            color: "#B4C7E7"

            Image {
                id: playerAvatar
                source: "assets/images/top_hat.png"
                anchors.bottom: playerCredits.bottom
                anchors.right: parent.right
                anchors.rightMargin: 15
                width: parent.width/4; height: parent.width/4
                fillMode:Image.PreserveAspectFit; clip: true;

            }

            Text {
                id: playerName
                text: "Player1"
                font.family: boldfont.name
                font.pixelSize: 22
                color: "#1F4E79"
                anchors.top: parent.top
                anchors.topMargin: 15
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.rightMargin: 15
            }

            Text {
                id: playerCredits
                text: "ECTS: 1500"
                font.family: boldfont.name
                font.pixelSize: 22
                color: "#1F4E79"
                anchors.top: playerName.bottom
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.rightMargin: 15
            }

            RoundButton {
                id: playerCheck
                contentItem: Text {
                    text: qsTr("Check cards")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: playerCredits.bottom
                anchors.topMargin: 40
                radius: 12
                width: parent.width/1.5
                height: parent.height/11

                background: Rectangle {
                    id: checkBackground
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                }

            }

            RoundButton {
                id: playerManage
                contentItem: Text {
                    text: qsTr("Manage properties")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: enabled? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: "WordWrap"
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: playerCheck.bottom
                anchors.topMargin: 15
                radius: 12
                width: parent.width/1.5
                height: parent.height/7

                background: Rectangle {
                    id: manageBackground
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked:
                    {
                        popupBackground.visible = true
                        manageWindow.visible = true
                    }
                    cursorShape: Qt.PointingHandCursor
                }

            }

            Image {
                id: playerDice
                source: "assets/images/dice.png"
                anchors.top: playerManage.bottom
                anchors.topMargin: 25
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width/2;
                fillMode:Image.PreserveAspectFit; clip: true;

                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {

                        game.rollDice()
                        server.actions(22)

                        if(game.getProperty()==="NULL")
                        {
                            server.sendNextPlayer()
                        }
                        else if(game.getProperty()==="PAYRENT")
                        {
                            server.sendNextPlayer()
                        }
                        else if (game.get_current_balance()>game.get_prop_price()){
                            popupBackground.visible = true
                            purchaseOptions.visible = true
                            propertyName.text = game.getProperty()
                            propertyPrice.text = game.getprice()
                        }
                        else{
                            server.sendNextPlayer()
                        }
                    }
                }
            }

            RoundButton {
                id: playerForfeit
                contentItem: Text {
                    text: qsTr("Forfeit")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: "WordWrap"
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                radius: 12
                width: parent.width/1.5
                height: parent.height/11

                background: Rectangle {
                    id: forfeitBackground
                    color: parent.enabled ? "#E44C35" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#C00000" : "#A6A6A6"
                }

                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        myStack.clear()
                        server.closeserver()
                        myStack.push("mainMenu.qml")
                    }
                }
            }
        }


        Rectangle{
            id: opponent1Banner
            width: parent.width/5.2
            height: parent.height/6.5
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.topMargin: 20
            anchors.rightMargin: 20
            border.width: 5
            border.color: "#BF9000"
            radius: 30
            color: "#FFF2CC"

            Image {
                id: opponent1Avatar
                source: "assets/images/bengala.png"
                anchors.bottom: opponent1Credits.bottom
                anchors.right: parent.right
                anchors.rightMargin: 15
                width: parent.width/4; height: parent.width/4
                fillMode:Image.PreserveAspectFit; clip: true;

            }

            Text {
                id: opponent1Name
                text: "Player2"
                font.family: boldfont.name
                font.pixelSize: 22
                color: "#BF9000"
                anchors.bottom: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.rightMargin: 15
            }

            Text {
                id: opponent1Credits
                text: "ECTS: 1500"
                font.family: boldfont.name
                font.pixelSize: 22
                color: "#BF9000"
                anchors.top: opponent1Name.bottom
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.rightMargin: 15
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    popupBackground.visible = true
                    opponent1Options.visible = true
                }
                cursorShape: Qt.PointingHandCursor
            }
        }

        Rectangle{
            id: opponent2Banner
            width: parent.width/5.2
            height: parent.height/6.5
            anchors.top: opponent1Banner.bottom
            anchors.right: parent.right
            anchors.topMargin: 20
            anchors.rightMargin: 20
            border.width: 5
            border.color: "#385723"
            radius: 30
            color: "#E2F0D9"

            Image {
                id: opponent2Avatar
                source: "assets/images/gandafino.png"
                anchors.bottom: opponent2Credits.bottom
                anchors.right: parent.right
                anchors.rightMargin: 15
                width: parent.width/4; height: parent.width/4
                fillMode:Image.PreserveAspectFit; clip: true;
            }

            Text {
                id: opponent2Name
                text: "Player3"
                font.family: boldfont.name
                font.pixelSize: 22
                color: "#385723"
                anchors.bottom: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.rightMargin: 15
            }

            Text {
                id: opponent2Credits
                text: "ECTS: 1500"
                font.family: boldfont.name
                font.pixelSize: 22
                color: "#385723"
                anchors.top: opponent2Name.bottom
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.rightMargin: 15
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    popupBackground.visible = true
                    opponent2Options.visible = true
                }
                cursorShape: Qt.PointingHandCursor
            }

        }

        Rectangle{
            id: opponent3Banner
            width: parent.width/5.2
            height: parent.height/6.5
            anchors.top: opponent2Banner.bottom
            anchors.right: parent.right
            anchors.topMargin: 20
            anchors.rightMargin: 20
            border.width: 5
            border.color: "#C00000"
            radius: 30
            color: "#F8CBAD"

            Image {
                id: opponent3Avatar
                source: "assets/images/colher.png"
                anchors.bottom: opponent3Credits.bottom
                anchors.right: parent.right
                anchors.rightMargin: 15
                width: parent.width/4; height: parent.width/4
                fillMode:Image.PreserveAspectFit; clip: true;
            }

            Text {
                id: opponent3Name
                text: "Player4"
                font.family: boldfont.name
                font.pixelSize: 22
                color: "#C00000"
                anchors.bottom: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.rightMargin: 15
            }

            Text {
                id: opponent3Credits
                text: "ECTS: 1500"
                font.family: boldfont.name
                font.pixelSize: 22
                color: "#C00000"
                anchors.top: opponent3Name.bottom
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.rightMargin: 15
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    popupBackground.visible = true
                    opponent3Options.visible = true
                }
                cursorShape: Qt.PointingHandCursor
            }
        }

        Rectangle{
            id: popupBackground
            width: 1280
            height: 720
            visible: false
            color: "#BDD7EE"
            opacity: 0.7
            MouseArea{
                anchors.fill: parent
                propagateComposedEvents: false
            }
        }

        Rectangle{
            id: jailOptions
            width: parent.width/1.3
            height: parent.height/2.1
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"
            visible: false

            Text {
                id: jailTitle
                text: qsTr("You're in jail!")
                font.family: boldfont.name
                font.pixelSize: 35
                width: parent.width/1.6
                color: "#1F4E79"
                anchors.top: parent.top
                anchors.topMargin: 30
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                clip: true
            }

            Image {
                id: jailImage
                source: "assets/images/praxislogo.png"
                anchors.top: jailTitle.bottom
                anchors.topMargin: 15
                anchors.horizontalCenter: parent.horizontalCenter
                width: 200
                fillMode:Image.PreserveAspectFit; clip: true;
            }

            RoundButton {
                id: payBailButton
                contentItem: Text {
                    text: qsTr("Pay 50 ECTS Bail")
                    font.family: boldfont.name
                    font.pixelSize: 25
                    color: enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.top: jailImage.top
                anchors.right: jailImage.left
                anchors.rightMargin: 30
                width: parent.width/4
                height: parent.height/5
                radius: 12
                enabled: false

                background: Rectangle {
                    id: payBailBackground
                    anchors.fill: parent
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                    width: parent.width
                    height: parent.height
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        jailOptions.visible = false
                        popupBackground.visible = false
                        game.payBail()
                    }
                }
            }

            RoundButton {
                id: useCardButton
                contentItem: Text {
                    text: qsTr("Use a Card")
                    font.family: boldfont.name
                    font.pixelSize: 25
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.bottom: jailImage.bottom
                anchors.right: jailImage.left
                anchors.rightMargin: 30
                width: parent.width/4
                height: parent.height/5
                radius: 12

                background: Rectangle {
                    id: useCardBackground
                    anchors.fill: parent
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                    width: parent.width
                    height: parent.height
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        jailOptions.visible = false
                        popupBackground.visible = false
                    }
                }
            }

            RoundButton {
                id: rollJailButton
                contentItem: Text {
                    text: qsTr("Roll Doubles")
                    font.family: boldfont.name
                    font.pixelSize: 25
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.top: jailImage.top
                anchors.left: jailImage.right
                anchors.leftMargin: 30
                width: parent.width/4
                height: parent.height/5
                radius: 12

                background: Rectangle {
                    id: rollJailBackground
                    anchors.fill: parent
                    color: "#1F4E79"
                    radius: parent.radius
                    border.width: 3
                    border.color: "#112B43"
                    width: parent.width
                    height: parent.height
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        jailOptions.visible = false
                        popupBackground.visible = false
                        if(!game.tryDouble()){
                            server.sendNextPlayer()
                        }
                    }
                }
            }

            RoundButton {
                id: stayJailButton
                contentItem: Text {
                    text: qsTr("Stay in Jail")
                    font.family: boldfont.name
                    font.pixelSize: 25
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.bottom: jailImage.bottom
                anchors.left: jailImage.right
                anchors.leftMargin: 30
                width: parent.width/4
                height: parent.height/5
                radius: 12

                background: Rectangle {
                    id: stayJailBackground
                    anchors.fill: parent
                    color: "#1F4E79"
                    radius: parent.radius
                    border.width: 3
                    border.color: "#112B43"
                    width: parent.width
                    height: parent.height
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        jailOptions.visible = false
                        popupBackground.visible = false
                        server.sendNextPlayer()
                    }
                }
            }
        }

        Rectangle {
            id: tradePopup
            visible: false
            width: parent.width/1.8
            height: parent.height/2
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"

            Text {
                id: tradePopupLabel
                text: qsTr("Do you want to sell this property?")
                font.family: boldfont.name
                font.pixelSize: 30
                color: "#203864"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 15
            }

            Text {
                id: tradePropertyNameLabel
                text: qsTr("Property Name: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.top: tradePopupLabel.bottom
                anchors.topMargin: 35

            }

            Text {
                id: tradePropertyName
                text: qsTr("{property_name}")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: tradePropertyNameLabel.right
                anchors.leftMargin: 10
                anchors.verticalCenter: tradePropertyNameLabel.verticalCenter
            }

            Text {
                id: tradePriceLabel
                text: qsTr("Price (ECTS): ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.top: tradePropertyNameLabel.bottom
                anchors.topMargin: 15

            }

            Text {
                id: tradePropertyPrice
                text: qsTr("{property_price}")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: tradePriceLabel.right
                anchors.leftMargin: 10
                anchors.verticalCenter: tradePriceLabel.verticalCenter
            }

            Text {
                id: tradeBuyerLabel
                text: qsTr("Buyer: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.top: tradePriceLabel.bottom
                anchors.topMargin: 35

            }

            Text {
                id: tradeBuyerName
                text: qsTr("{buyer_name}")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: tradeBuyerLabel.right
                anchors.leftMargin: 10
                anchors.verticalCenter: tradeBuyerLabel.verticalCenter
            }

            RoundButton {
                id: acceptTrade
                contentItem: Text {
                    text: qsTr("Yes")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                radius: 12
                width: parent.width/5
                height: parent.height/6

                background: Rectangle {
                    id: acceptTradeBackground
                    color: "#1F4E79"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: "#112B43"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        popupBackground.visible = false
                        tradePopup.visible = false
                    }
                }
            }

            RoundButton {
                id: declineTrade
                contentItem: Text {
                    text: qsTr("No")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.left: parent.horizontalCenter
                anchors.leftMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                radius: 12
                width: parent.width/5
                height: parent.height/6

                background: Rectangle {
                    id: declineTradeBackground
                    color: "#1F4E79"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: "#112B43"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        popupBackground.visible = false
                        tradePopup.visible = false
                    }
                }
            }

        }

        Rectangle {
            id: opponentCheckWindow
            visible: false
            width: parent.width/1.5
            height: parent.height/1.2
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"

            Text {
                id: opponentCheckTitle
                text: qsTr("Check properties")
                font.family: boldfont.name
                font.pixelSize: 25
                color: "#1F4E79"
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Image {
                id: opponentCheckReturn
                source: "assets/images/back_arrow.png"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                anchors.horizontalCenter: parent.horizontalCenter
                width: 80
                fillMode:Image.PreserveAspectFit; clip: true;

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        popupBackground.visible = false
                        opponentCheckWindow.visible = false
                        opponent1CheckList.visible = false
                        opponent2CheckList.visible = false
                        opponent3CheckList.visible = false
                    }
                    cursorShape: Qt.PointingHandCursor
                }
            }

            ListView {
                id: opponent1CheckList
                anchors.top: opponentCheckTitle.bottom
                anchors.topMargin: 60
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.bottom: opponentCheckReturn.top
                anchors.bottomMargin: 40
                width: parent.width/2.5
                spacing: 10

                visible: false

                model: ListModel {

                    id: opponent1List


                }

                delegate: Rectangle {
                    width: opponentCheckWindow.width/2.5
                    height: 50
                    color: opponent1CheckList.currentIndex === index ? "#1F4E79" : "#9DC3E6"
                    border.color: "#203864"
                    border.width: 2
                    radius: 10

                    Text {
                        id: opponent1CheckName
                        text: propName
                        font.family: boldfont.name
                        font.pixelSize: 20
                        color: opponent1CheckList.currentIndex === index ? "#FFFFFF" : "#203864"
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                                opponent1CheckList.currentIndex = index
                                opponentCheckColorValue.text = propColor
                                opponentCheckRentValue.text = game.getRent(opponent1CheckName.text)
                                opponentCheckHousesValue.text = game.getHouses(opponent1CheckName.text)

                        }
                        cursorShape: Qt.PointingHandCursor
                    }

                }

                ScrollBar.vertical: ScrollBar {
                    height: 200
                    width: 10
                    policy: ScrollBar.AsNeeded
                    anchors.left: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    background: Rectangle {
                        color: "#FFFFFF"
                        border.color: "#203864"
                        border.width: 1
                        radius: 5
                    }
                    contentItem: Rectangle {
                        implicitWidth: 10
                        implicitHeight: 10
                        radius: 5
                        color: "#203864"
                    }
                }

            }

            ListView {
                id: opponent2CheckList
                anchors.top: opponentCheckTitle.bottom
                anchors.topMargin: 60
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.bottom: opponentCheckReturn.top
                anchors.bottomMargin: 40
                width: parent.width/2.5
                spacing: 10

                visible: false

                model: ListModel {

                    id: opponent2List


                }

                delegate: Rectangle {
                    width: opponentCheckWindow.width/2.5
                    height: 50
                    color: opponent2CheckList.currentIndex === index ? "#1F4E79" : "#9DC3E6"
                    border.color: "#203864"
                    border.width: 2
                    radius: 10

                    Text {
                        id: opponent2CheckName
                        text: propName
                        font.family: boldfont.name
                        font.pixelSize: 20
                        color: opponent2CheckList.currentIndex === index ? "#FFFFFF" : "#203864"
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                                opponent2CheckList.currentIndex = index
                                opponentCheckColorValue.text = propColor
                                opponentCheckRentValue.text = game.getRent(opponent2CheckName.text)
                                opponentCheckHousesValue.text = game.getHouses(opponent2CheckName.text)
                        }
                        cursorShape: Qt.PointingHandCursor
                    }

                }

                ScrollBar.vertical: ScrollBar {
                    height: 200
                    width: 10
                    policy: ScrollBar.AsNeeded
                    anchors.left: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    background: Rectangle {
                        color: "#FFFFFF"
                        border.color: "#203864"
                        border.width: 1
                        radius: 5
                    }
                    contentItem: Rectangle {
                        implicitWidth: 10
                        implicitHeight: 10
                        radius: 5
                        color: "#203864"
                    }
                }

            }

            ListView {
                id: opponent3CheckList
                anchors.top: opponentCheckTitle.bottom
                anchors.topMargin: 60
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.bottom: opponentCheckReturn.top
                anchors.bottomMargin: 40
                width: parent.width/2.5
                spacing: 10

                visible: false

                model: ListModel {

                    id: opponent3List

                }

                delegate: Rectangle {
                    width: opponentCheckWindow.width/2.5
                    height: 50
                    color: opponent3CheckList.currentIndex === index ? "#1F4E79" : "#9DC3E6"
                    border.color: "#203864"
                    border.width: 2
                    radius: 10

                    Text {
                        id: opponentCheck3Name
                        text: propName
                        font.family: boldfont.name
                        font.pixelSize: 20
                        color: opponent3CheckList.currentIndex === index ? "#FFFFFF" : "#203864"
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                                opponent3CheckList.currentIndex = index
                                opponentCheckColorValue.text = propColor
                                opponentCheckRentValue.text = game.getRent(opponentCheck3Name.text)
                                opponentCheckHousesValue.text = game.getHouses(opponentCheck3Name.text)
                        }
                        cursorShape: Qt.PointingHandCursor
                    }

                }

                ScrollBar.vertical: ScrollBar {
                    height: 200
                    width: 10
                    policy: ScrollBar.AsNeeded
                    anchors.left: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    background: Rectangle {
                        color: "#FFFFFF"
                        border.color: "#203864"
                        border.width: 1
                        radius: 5
                    }
                    contentItem: Rectangle {
                        implicitWidth: 10
                        implicitHeight: 10
                        radius: 5
                        color: "#203864"
                    }
                }

            }

            TextField {
                id: offerPropertyInput
                anchors.left: offerProperty.left
                anchors.bottom: offerProperty.top
                anchors.bottomMargin: 10
                font.pixelSize: 18
                font.family: boldfont.name
                selectionColor: "#203864"
                color: "#203864"
                maximumLength: 4
                focus: true
                height: offerProperty.height
                width: offerProperty.width/1.5

                validator: IntValidator {
                    bottom: 0
                    top: 9999
                }

                background: Rectangle {
                    color: "white"
                    border.width: 2
                    width: parent.width/1.5
                    height: parent.height
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    border.color: "#203864"
                    radius: 10

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.IBeamCursor
                    }
                }
                cursorDelegate: Rectangle {
                        id: cursor
                        visible: false
                        color: "#203864"
                        width: offerPropertyInput.cursorRectangle.width*2

                        SequentialAnimation {
                            loops: Animation.Infinite
                            running: offerPropertyInput.cursorVisible

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

            RoundButton {
                id: offerProperty
                width: opponentCheckWindow.width/2.5
                height: 40
                radius: 10
                anchors.right: parent.right
                anchors.rightMargin: 40
                anchors.bottom: opponentCheckReturn.top
                anchors.bottomMargin: 100

                background: Rectangle {
                    id: offerPropertyBackground
                    anchors.fill: parent
                    color: "#1F4E79"
                    radius: parent.radius
                    border.width: 2
                    border.color: "#112B43"
                    width: parent.width
                    height: parent.height
                }

                Text {
                    id: offerPropertyLabel
                    text: qsTr("Make an Offer")
                    font.family: mediumfont.name
                    font.pixelSize: 20
                    color: "#FFFFFF"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                }
            }

            Text {
                id: opponentCheckRentLabel
                text: qsTr("Rent (ECTS): ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: offerProperty.left
                anchors.top: opponentCheckTitle.bottom
                anchors.topMargin: 60

            }

            Text {
                id: opponentCheckRentValue
                text: qsTr("?")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: opponentCheckRentLabel.right
                anchors.leftMargin: 5
                anchors.bottom: opponentCheckRentLabel.bottom
            }

            Text {
                id: opponentCheckHousesLabel
                text: qsTr("Houses: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: opponentCheckRentLabel.left
                anchors.top: opponentCheckRentLabel.bottom
                anchors.topMargin: 5
            }

            Text {
                id: opponentCheckHousesValue
                text: qsTr("0")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: opponentCheckHousesLabel.right
                anchors.leftMargin: 5
                anchors.bottom: opponentCheckHousesLabel.bottom
            }

            Text {
                id: opponentCheckColorLabel
                text: qsTr("Color: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: opponentCheckRentLabel.left
                anchors.top: opponentCheckHousesLabel.bottom
                anchors.topMargin: 5

            }

            Text {
                id: opponentCheckColorValue
                text: qsTr("?")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: opponentCheckColorLabel.right
                anchors.leftMargin: 5
                anchors.bottom: opponentCheckColorLabel.bottom
            }

            Text {
                id: opponentCheckMortgageLabel
                text: qsTr("Mortgage: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: opponentCheckRentLabel.left
                anchors.top: opponentCheckColorLabel.bottom
                anchors.topMargin: 5
            }

            Text {
                id: opponentCheckMortgageValue
                text: qsTr("No")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: opponentCheckMortgageLabel.right
                anchors.leftMargin: 5
                anchors.bottom: opponentCheckMortgageLabel.bottom
            }

        }

        Rectangle{
            id: communityChanceBox
            width: parent.width/1.3
            height: parent.height/2
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"
            visible: false

            Text {
                id: communityChanceText
                text: qsTr("< Consequence Message >")
                font.family: boldfont.name
                font.pixelSize: 28
                wrapMode: Text.WordWrap
                width: parent.width/1.6
                color: "#1F4E79"
                anchors.top: communityChanceBox.top
                anchors.topMargin: 40
                anchors.left: communityChanceBox.left
                anchors.leftMargin: 40
                anchors.right: communityChanceImage.left
                anchors.rightMargin: 40
                anchors.bottom: communityChanceButton.top
                anchors.bottomMargin: 40
                verticalAlignment: Text.AlignVCenter
                clip: true
            }

            Image {
                id: communityChanceImage
                source: "assets/images/unipoly_logo.png"
                anchors.right: communityChanceBox.right
                anchors.rightMargin: 15
                anchors.verticalCenter: communityChanceText.verticalCenter
                width: 190
                fillMode:Image.PreserveAspectFit; clip: true;
            }

            RoundButton {
                id: communityChanceButton
                contentItem: Text {
                    text: qsTr("OK")
                    font.family: boldfont.name
                    font.pixelSize: 25
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.bottom: communityChanceBox.bottom
                anchors.bottomMargin: 15
                anchors.horizontalCenter: communityChanceBox.horizontalCenter
                width: parent.width/8
                height: parent.height/6
                radius: 12

                background: Rectangle {
                    id: communityChanceButtonBackground
                    anchors.fill: parent
                    color: "#1F4E79"
                    radius: parent.radius
                    border.width: 3
                    border.color: "#112B43"
                    width: parent.width
                    height: parent.height
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        communityChanceBox.visible = false
                        popupBackground.visible = false
                    }
                }
            }
        }


        Rectangle {
            id: manageWindow
            visible: false
            width: parent.width/1.5
            height: parent.height/1.2
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"

            Text {
                id: manageTitle
                text: qsTr("Manage properties")
                font.family: boldfont.name
                font.pixelSize: 25
                color: "#1F4E79"
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Image {
                id: manageReturn
                source: "assets/images/back_arrow.png"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                anchors.horizontalCenter: parent.horizontalCenter
                width: 80
                fillMode:Image.PreserveAspectFit; clip: true;

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        popupBackground.visible = false
                        manageWindow.visible = false
                    }
                    cursorShape: Qt.PointingHandCursor
                }
            }

            ListView {
                id: manageList
                anchors.top: manageTitle.bottom
                anchors.topMargin: 60
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.bottom: manageReturn.top
                anchors.bottomMargin: 40
                width: parent.width/2.5
                spacing: 10

                model: ListModel {
                    id: manageModel
                }

                delegate: Rectangle {
                    width: manageWindow.width/2.5
                    height: 50
                    color: manageList.currentIndex === index ? "#1F4E79" : "#9DC3E6"
                    border.color: "#203864"
                    border.width: 2
                    radius: 10

                    Text {
                        id: manageName
                        text: propName
                        font.family: boldfont.name
                        font.pixelSize: 20
                        color: manageList.currentIndex === index ? "#FFFFFF" : "#203864"
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                                manageList.currentIndex = index
                                manageRentValue.text = game.getRent(propName)
                                manageColorValue.text = propColor
                                manageHousesValue.text = game.getHouses(propName)
                                game.property=propName
                                if(game.getHouses(propName)<5 || game.getMortgage_status(propName)===true){

                                    buyHouse.enabled=true
                                }
                                if(game.getHouses(propName)===5 || game.getMortgage_status(propName)===true || game.get_current_balance()<game.getBuildHousePrice(propName)){
                                    buyHouse.enabled=false
                                }
                                if(game.getBuildHousePrice(propName)===0){
                                    buyHouse.enabled=false
                                    sellHouse.enabled=false
                                }
                                if(game.getHouses(propName)>0){
                                    sellHouse.enabled=true
                                }
                                manageHousePriceValue.text = game.getBuildHousePrice(propName)
                                unmortgageProperty.enabled = game.getMortgage_status(propName)
                                mortgageProperty.enabled = !game.getMortgage_status(propName)
                        }
                        cursorShape: Qt.PointingHandCursor
                    }

                }

                ScrollBar.vertical: ScrollBar {
                    height: 200
                    width: 10
                    policy: ScrollBar.AsNeeded
                    anchors.left: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    background: Rectangle {
                        color: "#FFFFFF"
                        border.color: "#203864"
                        border.width: 1
                        radius: 5
                    }
                    contentItem: Rectangle {
                        implicitWidth: 10
                        implicitHeight: 10
                        radius: 5
                        color: "#203864"
                    }
                }

            }

            RoundButton {
                id: unmortgageProperty
                width: manageWindow.width/2.5
                height: 40
                radius: 10
                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.bottom: manageList.bottom
                enabled: false

                background: Rectangle {
                    anchors.fill: parent
                    color: parent.enabled? "#1F4E79" : "#D9D9D9"
                    border.color: parent.enabled? "#112B43" : "#A6A6A6"
                    border.width: 2
                    radius: 10
                }

                Text {
                    id: unmortgagePropertyLabel
                    text: qsTr("Unmortgage Property")
                    font.family: mediumfont.name
                    font.pixelSize: 20
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        game.unmortgageProperty(game.property)
                        unmortgageProperty.enabled = false
                        mortgageProperty.enabled = true

                        if(game.getHouses(game.property)<5 && game.getHouses(game.property)>=0){
                            buyHouse.enabled=true
                        }
                        if(game.getHouses(game.property)===5 || game.get_current_balance()<game.getBuildHousePrice(game.property)){
                            buyHouse.enabled=false
                        }
                        if(game.getHouses(game.property)>0){
                            sellHouse.enabled=true
                        }
                        if(game.getBuildHousePrice(game.property)===0){
                            buyHouse.enabled=false
                            sellHouse.enabled=false
                        }
                    }
                }
            }

            RoundButton {
                id: mortgageProperty
                width: manageWindow.width/2.5
                height: 40
                radius: 10
                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.bottom: unmortgageProperty.top
                anchors.bottomMargin: 5
                enabled: false

                background: Rectangle {
                    anchors.fill: parent
                    color: parent.enabled? "#1F4E79" : "#D9D9D9"
                    border.color: parent.enabled? "#112B43" : "#A6A6A6"
                    border.width: 2
                    radius: 10
                }

                Text {
                    id: mortgagePropertyLabel
                    text: qsTr("Mortgage Property")
                    font.family: mediumfont.name
                    font.pixelSize: 20
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        game.mortgageProperty(game.property)
                        mortgageProperty.enabled = false
                        unmortgageProperty.enabled = true
                        buyHouse.enabled=false
                        sellHouse.enabled=false

                    }
                }

            }

            Text {
                id: manageRentLabel
                text: qsTr("Rent (ECTS): ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: sellHouse.left
                anchors.top: manageList.top

            }

            Text {
                id: manageRentValue
                text: qsTr("?")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: manageRentLabel.right
                anchors.leftMargin: 5
                anchors.bottom: manageRentLabel.bottom
            }

            Text {
                id: manageHousesLabel
                text: qsTr("Houses: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: sellHouse.left
                anchors.top: manageRentLabel.bottom
                anchors.topMargin: 5
            }

            Text {
                id: manageHousesValue
                text: qsTr("0")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: manageHousesLabel.right
                anchors.leftMargin: 5
                anchors.bottom: manageHousesLabel.bottom
            }

            Text {
                id: manageHousePriceLabel
                text: qsTr("House Price: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: sellHouse.left
                anchors.top: manageHousesLabel.bottom
                anchors.topMargin: 5
            }

            Text {
                id: manageHousePriceValue
                text: qsTr("?")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: manageHousePriceLabel.right
                anchors.leftMargin: 5
                anchors.bottom: manageHousePriceLabel.bottom
            }

            Text {
                id: manageColorLabel
                text: qsTr("Color: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: sellHouse.left
                anchors.top: manageHousePriceLabel.bottom
                anchors.topMargin: 5

            }

            Text {
                id: manageColorValue
                text: qsTr("?")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: manageColorLabel.right
                anchors.leftMargin: 5
                anchors.bottom: manageColorLabel.bottom
            }

            Text {
                id: manageMortgageLabel
                text: qsTr("Mortgage: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: buyHouse.left
                anchors.top: manageColorLabel.bottom
                anchors.topMargin: 5
            }

            Text {
                id: manageMortgageValue
                text: qsTr("No")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: manageMortgageLabel.right
                anchors.leftMargin: 5
                anchors.bottom: manageMortgageLabel.bottom
            }

            RoundButton {
                id: sellHouse
                width: manageWindow.width/2.5
                height: 40
                radius: 10
                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.bottom: mortgageProperty.top
                anchors.bottomMargin: 5
                enabled: false
                background: Rectangle {
                    anchors.fill: parent
                    color: parent.enabled? "#1F4E79" : "#D9D9D9"
                    border.color: parent.enabled? "#112B43" : "#A6A6A6"
                    border.width: 2
                    radius: 10
                }

                Text {
                    id: sellHouseLabel
                    text: qsTr("Sell House")
                    font.family: mediumfont.name
                    font.pixelSize: 20
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        //want to sell the house that is specified above by propGame
                        game.sellHouse(game.property)
                        manageHousesValue.text = game.getHouses(game.property)
                        manageRentValue.text = game.getRent(game.property)
                        buyHouse.enabled = true
                        if(game.getHouses(game.property)===0){
                            sellHouse.enabled=false
                        }
                        if(game.getPlayerCredits(0)<game.getBuildHousePrice(game.property)){
                            buyHouse.enabled=false
                        }
                    }
                }
            }

            RoundButton {
                id: buyHouse
                width: manageWindow.width/2.5
                height: 40
                radius: 10
                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.bottom: sellHouse.top
                anchors.bottomMargin: 5
                enabled: false

                background: Rectangle {
                    anchors.fill: parent
                    color: parent.enabled? "#1F4E79" : "#D9D9D9"
                    border.color: parent.enabled? "#112B43" : "#A6A6A6"
                    border.width: 2
                    radius: 10
                }

                Text {
                    id: buyHouseLabel
                    text: qsTr("Buy House")
                    font.family: mediumfont.name
                    font.pixelSize: 20
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        //want to buy the house that is specified above by propGame
                        game.buyHouse(game.property)
                        manageHousesValue.text = game.getHouses(game.property)
                        manageRentValue.text = game.getRent(game.property)
                        sellHouse.enabled = true
                        if(game.getHouses(game.property)===5 || game.get_current_balance() < game.getBuildHousePrice(game.property)){
                            buyHouse.enabled=false
                        }
                    }
                }
            }

        }

        Rectangle {
            id: purchaseOptions
            visible: false
            width: parent.width/1.8
            height: parent.height/2.6
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"

            Text {
                id: purchaseLabel
                text: qsTr("Do you want to buy this property?")
                font.family: boldfont.name
                font.pixelSize: 30
                color: "#203864"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 15
            }

            Text {
                id: purchaseNameLabel
                text: qsTr("Property Name: ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.top: purchaseLabel.bottom
                anchors.topMargin: 35

            }

            Text {
                id: propertyName
                text: qsTr("{property_name}")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: purchaseNameLabel.right
                anchors.leftMargin: 10
                anchors.verticalCenter: purchaseNameLabel.verticalCenter
            }

            Text {
                id: purchasePriceLabel
                text: qsTr("Price (ECTS): ")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.top: purchaseNameLabel.bottom
                anchors.topMargin: 15

            }

            Text {
                id: propertyPrice
                text: qsTr("{property_price}")
                font.family: boldfont.name
                font.pixelSize: 20
                color: "#203864"
                anchors.left: purchasePriceLabel.right
                anchors.leftMargin: 10
                anchors.verticalCenter: purchasePriceLabel.verticalCenter
            }

            RoundButton {
                id: acceptPurchase
                contentItem: Text {
                    text: qsTr("Yes")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                radius: 12
                width: parent.width/5
                height: parent.height/6

                background: Rectangle {
                    id: acceptBackground
                    color: "#1F4E79"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: "#112B43"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        popupBackground.visible = false
                        purchaseOptions.visible = false
                        game.buyProperty()
                        server.changePropOwner()
                        server.sendNextPlayer()
                    }
                }
            }

            RoundButton {
                id: declinePurchase
                contentItem: Text {
                    text: qsTr("No")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.left: parent.horizontalCenter
                anchors.leftMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                radius: 12
                width: parent.width/5
                height: parent.height/6

                background: Rectangle {
                    id: declineBackground
                    color: "#1F4E79"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: "#112B43"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        popupBackground.visible = false
                        purchaseOptions.visible = false
                        server.sendNextPlayer()
                    }
                }
            }

        }

        Rectangle {
            id: opponent1Options
            visible: false
            Text {
                text: qsTr(opponent1Name.text)
                font.family: boldfont.name
                font.pixelSize: 30
                color: "#203864"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 15
            }
            width: parent.width/3
            height: parent.height/2.2
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"

            RoundButton {
                id: opponent1Trade
                contentItem: Text {
                    text: qsTr("Trade")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: opponent1Check.top
                anchors.bottomMargin: 20
                radius: 12
                width: parent.width/1.3
                height: parent.height/6

                background: Rectangle {
                    id: trade1Background
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                }
            }

            RoundButton {
                id: opponent1Check
                contentItem: Text {
                    text: qsTr("Check properties")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.verticalCenter
                radius: 12
                width: parent.width/1.3
                height: parent.height/6

                background: Rectangle {
                    id: check1Background
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                }

                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        opponentCheckWindow.visible = true
                        opponent1Options.visible = false
                        opponent1CheckList.visible = true
                    }
                }
            }

            Image {
                id: options1Return
                source: "assets/images/back_arrow.png"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width/5
                fillMode:Image.PreserveAspectFit; clip: true;

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        popupBackground.visible = false
                        opponent1Options.visible = false
                    }
                    cursorShape: Qt.PointingHandCursor
                }
            }
        }

        Rectangle {
            id: opponent2Options
            visible: false
            Text {
                text: qsTr(opponent2Name.text)
                font.family: boldfont.name
                font.pixelSize: 30
                color: "#203864"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 15
            }
            width: parent.width/3
            height: parent.height/2.2
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"

            RoundButton {
                id: opponent2Trade
                contentItem: Text {
                    text: qsTr("Trade")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: opponent2Check.top
                anchors.bottomMargin: 20
                radius: 12
                width: parent.width/1.3
                height: parent.height/6

                background: Rectangle {
                    id: trade2Background
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                }
            }

            RoundButton {
                id: opponent2Check
                contentItem: Text {
                    text: qsTr("Check properties")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.verticalCenter
                radius: 12
                width: parent.width/1.3
                height: parent.height/6

                background: Rectangle {
                    id: check2Background
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                }

                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        opponentCheckWindow.visible = true
                        opponent2Options.visible = false
                        opponent2CheckList.visible = true
                    }
                }
            }

            Image {
                id: options2Return
                source: "assets/images/back_arrow.png"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width/5
                fillMode:Image.PreserveAspectFit; clip: true;

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        popupBackground.visible = false
                        opponent2Options.visible = false
                    }
                    cursorShape: Qt.PointingHandCursor
                }
            }
        }

        Rectangle {
            id: opponent3Options
            visible: false
            Text {
                text: qsTr(opponent3Name.text)
                font.family: boldfont.name
                font.pixelSize: 30
                color: "#203864"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 15
            }
            width: parent.width/3
            height: parent.height/2.2
            anchors.centerIn: parent
            radius: 35
            color: "#DAE3F3"
            border.width: 5
            border.color: "#203864"

            RoundButton {
                id: opponent3Trade
                contentItem: Text {
                    text: qsTr("Trade")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: opponent3Check.top
                anchors.bottomMargin: 20
                radius: 12
                width: parent.width/1.3
                height: parent.height/6

                background: Rectangle {
                    id: trade3Background
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                }
            }

            RoundButton {
                id: opponent3Check
                contentItem: Text {
                    text: qsTr("Check properties")
                    font.family: mediumfont.name
                    font.pixelSize: 25
                    color: parent.enabled ? "#FFFFFF" : "#7F7F7F"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.verticalCenter
                radius: 12
                width: parent.width/1.3
                height: parent.height/6

                background: Rectangle {
                    id: check3Background
                    color: parent.enabled ? "#1F4E79" : "#D9D9D9"
                    radius: parent.radius
                    anchors.fill: parent
                    border.width: 3
                    border.color: parent.enabled ? "#112B43" : "#A6A6A6"
                }

                MouseArea{
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        opponentCheckWindow.visible = true
                        opponent3Options.visible = false
                        opponent3CheckList.visible = true
                    }
                }
            }

            Image {
                id: options3Return
                source: "assets/images/back_arrow.png"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width/5
                fillMode:Image.PreserveAspectFit; clip: true;

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        popupBackground.visible = false
                        opponent3Options.visible = false
                    }
                    cursorShape: Qt.PointingHandCursor
                }
            }
        }
    }
}

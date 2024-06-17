import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Window
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import QtMultimedia

ApplicationWindow {

    width: 1280
    height: 720

    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height

    visible: true
    title: qsTr("Unipoly")

    StackView {
        id: myStack
        initialItem: "splash.qml"
        anchors.fill: parent

        replaceEnter: Transition {
                    PropertyAnimation {
                        property: "opacity"
                        from: 0
                        to:1
                        duration: 200
                        easing.type: Easing.OutQuad
                    }
                }
        replaceExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
                easing.type: Easing.InQuad
            }
        }
    }

    MediaPlayer {

        id: music
        source: "assets/audio/menumusic.mp3"
        loops: MediaPlayer.Infinite
        property alias volumeExt: musicVolume
        audioOutput: AudioOutput {
            id: musicVolume
            volume: 0
        }
    }

    Component.onCompleted: {
        music.play()
    }

    FontLoader {
        id: boldfont
        source: "assets/fonts/KabelBdNormal.ttf"
    }

    FontLoader {
        id: mediumfont
        source: "assets/fonts/KabelMedium.ttf"
    }

    Component{

        id: settingsPage

        Rectangle {

            id: windowBackground
            width: 1280
            height: 720

            color: "#9DC3E6"

            Rectangle{
                id: buttonBackground
                width: parent.width/2.5
                height: parent.height/3.2
                y: parent.height/3.1
                border.width: 5
                border.color: "#203864"
                radius: 30
                color: "#DEEBF7"

                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: title
                    text: qsTr("Settings")
                    font.family: boldfont.name
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 40
                    font.pixelSize: 35
                    color: "#203864"
                 }

                Text {
                    id: volumeLabel
                    text: qsTr("Volume")
                    font.family: boldfont.name
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: title.bottom
                    anchors.topMargin: 25
                    font.pixelSize: 20
                    color: "#203864"
                 }

                Image {
                    id: volumelogo
                    source: if (audiocontrol.value === 0) "assets/images/volume_disabled.png"
                            else "assets/images/volumelogo.png"
                    anchors.top: volumeLabel.bottom
                    anchors.topMargin: -20
                    anchors.left: parent.left
                    anchors.leftMargin: 75
                    width:100; height: 100
                    fillMode:Image.PreserveAspectFit; clip: true;
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            if (musicVolume.volume > 0) {
                                musicVolume.volume = 0
                                volumelogo.source = "assets/images/volume_disabled.png"
                            }
                            else if (audiocontrol.value === 0){
                                musicVolume.volume = 0.01
                                audiocontrol.value = 0.01
                                volumelogo.source = "assets/images/volumelogo.png"
                            }
                            else {
                                musicVolume.volume = audiocontrol.value
                                volumelogo.source = "assets/images/volumelogo.png"
                            }
                        }
                        cursorShape: Qt.PointingHandCursor
                    }

                }

                Slider {
                    id: audiocontrol
                    value: musicVolume.volume
                    from: 0
                    to: 1

                    live: true

                    anchors.verticalCenter: volumelogo.verticalCenter
                    anchors.left: volumelogo.right

                    background: Rectangle {
                        x: audiocontrol.leftPadding
                        y: audiocontrol.topPadding + audiocontrol.availableHeight / 2 - height / 2
                        implicitWidth: 200
                        implicitHeight: 10
                        width: audiocontrol.availableWidth
                        height: implicitHeight
                        radius: 13
                        color: "white"


                        Rectangle {
                            width: audiocontrol.visualPosition * parent.width
                            height: parent.height
                            color: "#8FAADC"
                            radius: 2
                        }

                        Rectangle {
                            width: parent.width
                            height: parent.height
                            radius: 13
                            color: "transparent"
                            border.color: "#203864"
                        }
                    }

                    handle: Rectangle {
                        x: audiocontrol.leftPadding + audiocontrol.visualPosition * (audiocontrol.availableWidth - width)
                        y: audiocontrol.topPadding + audiocontrol.availableHeight / 2 - height / 2
                        implicitWidth: 26
                        implicitHeight: 26
                        radius: 13
                        color: "#203864"
                        border.color: "#203864"
                    }

                    onValueChanged:
                    {
                        musicVolume.volume = audiocontrol.value
                        if (audiocontrol.value === 0) {
                            volumelogo.source = "assets/images/volume_disabled.png"
                        }
                        else {
                            volumelogo.source = "assets/images/volumelogo.png"
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

}

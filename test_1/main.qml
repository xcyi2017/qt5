import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
//    title: qsTr("Hello World")

//    MouseArea {
//        anchors.fill: parent
//        onClicked:
//        {
//            Qt.quit();
//        }

//        Text {
//            id: element
//            x: 406
//            y: 18
//            width: 206
//            height: 177
//            font.pixelSize: 12
//        }
//    }

//    Text {
//        text: qsTr("hello world")
//        anchors.centerIn: parent

//    }

//    Rectangle {
//        width: 200
//        height: 200


//        gradient: Gradient{
//            GradientStop {position:0.0; color: "yellow"}
//            GradientStop {position:1.0; color: "green"}
//        }

//        Text {
//            anchors.centerIn: parent
//            text: qsTr("Hello, QML!")
//            font.pointSize: 24
//            font.family: "Helvetica"
//        }
//    }

//    Item {

//        width: 310
//        height: 170
//        anchors.centerIn: parent

//        Column {
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.verticalCenter: parent.verticalCenter
//            spacing: 5
//            Rectangle {
//                color: "lightblue"
//                radius: 10
//                width: 300
//                height: 50
//                Text {
//                    anchors.centerIn: parent
//                    font.pointSize: 24
//                    text: "Books"
//                }
//            }

//            Rectangle {
//                color: "gold"
//                radius: 10
//                width: 300
//                height: 50
//                Text {
//                    anchors.centerIn: parent
//                    font.pointSize: 24
//                    text: "Music"
//                }
//            }

//            Rectangle {
//                color: "lightgreen"
//                radius: 10
//                width: 300
//                height: 50
//                Text {
//                    anchors.centerIn: parent
//                    font.pointSize: 24
//                    text: "Movies"
//                }
//            }
//        }
//    }

//    Button {
//        id: button
//        x: 12; y : 12
//        text: "Start"
//        onClicked: {
//            status.text = "Button clicked!!!"
//        }
//    }

//    Text {
//        // text will change when button pushed

//        id: status
//        x: 12; y: 76
//        width: 116; height: 26
//        text: "waiting ..."
//        horizontalAlignment: Text.AlignHCenter
//    }

//    Grid_{
//        x: 200
//        y: 200

//    }

//    Flow_ {}

//    Repeater_ {}

//    LayoutItem {}

//    TextInput_ {}

//    TextInput_1 {}

//    // 测试TlineEditV1

//    Rectangle {

//        width: parent.width; height: parent.height

//        TlineEditV1 {
//            id: input1
//            x: 8; y: 8
//            width: 96; height: 20
//            focus: true
//            text: "Text Input 1"
//            KeyNavigation.tab: input2
//        }

//        TlineEditV1 {
//            id: input2
//            x: 8; y: 36
//            width: 96; height: 20
//            focus: true
//            text: "Text Input 2"
//            KeyNavigation.tab: input1
//        }
//    }

    // 测试TlineEditV2

//    Rectangle {

//        width: parent.width; height: parent.height

//        TlineEditV2 {
//            id: input1
//            x: 8; y: 8
//            width: 96; height: 20
//            focus: true
//            text: "Text Input 1"
//            KeyNavigation.tab: input2
//        }

//        TlineEditV2 {
//            id: input2
//            x: 8; y: 36
//            width: 96; height: 20
//            focus: true
//            text: "Text Input 2"
//            KeyNavigation.tab: input1
//        }
//    }
    // 测试TTextEdit
//    Rectangle {
//        width: 136; height: 120
//        color: "linen"

//        TTextEdit {
//            id: input
//            x: 8; y: 8
//            width: 120; height: 104
//            focus: true
//            text: "Text Edit"
//        }
//    }

    // 测试KKey

    KKey {}


}

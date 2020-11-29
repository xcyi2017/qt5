import QtQuick 2.12
import QtQuick.Window 2.12
import an.qt.Gemini 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal qmlSignal(string message)
    onQmlSignal: console.log("qml signal message is", message)

    function qmlFunction(parameter) {
        console.log("qml function parameter is", parameter);
        return "function from qml";
    }

    Rectangle {
        objectName: "rect"
        anchors.fill: parent
        color: "yellow"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            gemini.begin();
            gemini.stop();
            gemini.ballNumber = 10;
            qmlSignal("This is a qml signal");
        }
    }

    Gemini {
        id: gemini
        onBegin: {
            doSomething(Gemini.BALL_COLOR_RED);
        }
        onBallNumberChanged: {
            console.log("New ball number is", ballNumber); // 10
        }
        Component.onCompleted: { // 当类加载完成时
            console.log("default ball number is", ballNumber); // 0
        }
    }
}

//import QtQuick 2.12
//import QtQuick.Window 2.12

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")


//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            gemini.begin();
//            gemini.stop();
//            gemini.ballNumber = 10;
//        }
//    }



//    Connections {
//        target: gemini
//        onBegin: {
//            console.log("aaaa");
//        }
//        onBallNumberChanged: {
//            console.log("hello");
//        }
//    }
//}

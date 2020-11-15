import QtQuick 2.12
import QtQuick.Window 2.12
import QtWebEngine 1.8
//Window {
//    visible: true

//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            Qt.quit();
//        }
//    }

//    Text {
//        anchors.centerIn: parent
//        text: qsTr("Hello world！")
//    }
//}

Window {
    visible: true
    width: 500
    height: 500
//    Rectangle {
//        width: parent.width/2
//        height: parent.height/2
//        x:parent.width/2-width/2
//        y:parent.height/2-height/2
//        color: "red"
//        border {
//            width:2
//            color: "black"
//        }

//        radius: parent.width/20
//    }
      WebEngineView {
          anchors.fill: parent
          url: "http://baidu.com"
          canGoBack: true
          canGoForward: true
      }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import QtWebEngine 1.8
import QtQuick.Controls 2.12
import Qt.WebSockets 1.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    
    WebEngineView {
        id:eChart
        anchors.fill: parent
        url: "qrc:/index.html"
        Component.onCompleted: {}
    } 
    // 创建websocket服务对象
    WebSocketServer {
        id: server 
        port: 12335
        listen: true
        onClientConnected: {
            webSocket.onTextMessageReceived.connect(function(message) {
                console.log("Server recevied message:%1".arg(message));
                webSocket.sendTextMessage(qsTr("Hello html"))
            }
                )
        }
        
        onErrorStringChanged: {
            console.log(qsTr("Server error:%1".arg(errorString)))
        }
        
        
    }
    
    Button {
        id: btFunc
        text: qsTr("Pressme")

       anchors.bottom: eChart.bottom
        onClicked: {
            eChart.runJavaScript("window.sayHelloFromQML(\"" + "Hello html" + "\")", function(result) {
                console.log(result);
            }
                )
        }
    }
}

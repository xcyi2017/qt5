import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("中文标题")

    Button {
        text:qsTr("这是一个按钮") // 标题
        height:40 // 按钮的高度
        width:120 // 按钮的宽度
        anchors.centerIn: parent // 按照父对象的位置居中
        onClicked: { // 单击事件
            image.source = "qrc:/images/pic.png"
        }
    }

    Button {
        text: qsTr("这是一个按钮") // 标题
        height: 40 // 按钮的高度
        width: 120 // 按钮的宽度
        anchors.left: parent.left // 按钮靠父窗口左边
        anchors.leftMargin: 12 // 距离边缘12像素
        anchors.verticalCenter: parent.verticalCenter // 纵向居中
    }

//    MouseArea {
//        anchors.fill: parent
//        hoverEnabled: true
//        onEntered: {
//            Image.source = "qrc:/images/pic.png"
//        }
//    }



}

import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.LocalStorage 2.12
import "DataBase.js" as JS

// 引入我们的JS文件
ApplicationWindow {
    visible: true
    width: 400
    height: 600

    title: qsTr("QML SQLite")


    ColumnLayout {
        anchors.fill: parent

        ToolBar {
            id: mytoolbar
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 40
            Layout.alignment: Qt.AlignTop
            Label {
                anchors.centerIn: parent
                text: "班级维护"

            }
        }

        InputPage {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 140
        }

        ListView {
            id: mylistview
            Layout.preferredWidth: parent.width * 0.9
            Layout.fillHeight: true
            model: MyModel {}
            delegate: MyDelegate {}

            Layout.alignment: Qt.AlignHCenter

            highlight: Rectangle {
                color: "lightsteelblue"
            }
            focus: true
        }

        ToolBar {
            id: myfootbar
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 40
            Layout.alignment: Qt.AlignBottom
            Label {
                anchors.centerIn: parent
                text: "xcy 为您服务"
            }
        }

    }

    Component.onCompleted: {
        JS.dbInit() // JS的文件初始化
    }
}

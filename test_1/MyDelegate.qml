import QtQuick 2.0
import QtQuick.Controls 2.12


Component {
    Column { // 美化的作用
        width: parent.width
        spacing: 0
        Rectangle {
            width: parent.width
            height: 20
            color: "transparent"
        }

        Row {
            width: parent.width

            height: 35
            spacing: 5


            Label {
                text: "班级名称"
                color: "blue"
                font.bold: true
                width: parent.width / 4
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mylistview.currentIndex = index // index为鼠标当前点击的记录编号
                        mylistview.focus = true
                    }
                }


            }

            Label {
                text: name
                width: parent.width / 4
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mylistview.currentIndex = index // index为鼠标当前点击的记录编号
                        mylistview.focus = true
                    }
                }


            }

            Label {
                text: "班主任老师"
                width: parent.width / 4
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mylistview.currentIndex = index // index为鼠标当前点击的记录编号
                        mylistview.focus = true
                    }
                }

            }

            Label {
                text: teacher
                width: parent.width / 4
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mylistview.currentIndex = index // index为鼠标当前点击的记录编号
                        mylistview.focus = true
                    }
                }

            }

        }
        Rectangle {
            width: parent.width
            height: 2
            color: "lightgreen"
        }
    }
}

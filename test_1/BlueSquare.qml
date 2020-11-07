import QtQuick 2.0

Rectangle {
    width: 48
    height: 48
    color: "#0000FF"
    border.color: Qt.lighter(color)

    property alias text: label.text

    Text {
        id: label
        text: ""
    }
}

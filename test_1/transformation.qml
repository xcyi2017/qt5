import QtQuick 2.0

Item {
    // set width based on given background
    width: bg.witdth
    height: bg.height

    Image {
        id: bg
        source: 'background.png'
    }

    MouseArea {
        id: backgroundClicker
        anchors.fill: parent
        onClicked: {

        }
    }
}

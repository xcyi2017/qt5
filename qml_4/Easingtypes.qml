import QtQuick 2.0

DarkSquare {
    id: root
    width: 600
    height: 340

    property variant easings: [
        "Linear", "InQuad", "OutQuad", "InOutQuad",
        "InCubic", "InSine", "InCirc", "InElastic",
        "InBack", "InBounce" ]

    Grid {
        id: container
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 16
        height: 200
        columns: 5
        spacing: 16
        Repeater {
            model: easings
            ClickableImageV3 {
                framed: true
                text: modelData
                source: "curves/" + modelData + ".png"

                onClicked: {
                    anim.easing.type = modelData
                    anim.restart()
                }
            }
        }
    }

    GreenSquare {
        id: square
        x: 60; y: 260
    }


    NumberAnimation {
        id: anim
        target: square
        from: 40; to: root.width - 40 - square.width
        properties: "x, y"
        duration: 4000
    }
}
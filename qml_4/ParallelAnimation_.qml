import QtQuick 2.0

BrightSquare {
    id: root
    width: 200
    height: 300
    property int duration: 3000

    ClickableImageV3 {
        id: rocket
        x: 20; y: 120
        source: "rocket.png"
        onClicked: anim.start()
    }

    ParallelAnimation {
        id: anim

        NumberAnimation {
            target: rocket
            properties: "y"
            to: 20
            duration: root.duration
        }


        NumberAnimation {
            target: rocket
            properties: "x"
            to: 160
            duration: root.duration
        }
    }
}

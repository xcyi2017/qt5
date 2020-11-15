import QtQuick 2.0

Image {
    source: "background.png"
    Image {
        x: 40; y:80
        source: "rocket.png"


        NumberAnimation on x {
            to: 240
            duration: 4000
            loops: Animation.Infinite
        }

        RotationAnimation on rotation {
            to: 360
            duration: 4000
            loops: Animation.Infinite
        }

    }
}

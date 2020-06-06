import QtQuick 2.10
import QtQuick.Window 2.2
import QtQuick.Shapes 1.0

Window {
    id: window
    title: "Test"
    visible: true
    width: 400
    height: 400

    Shape {
        width: 100
        height: 100
        anchors.centerIn: parent
        ShapePath {
            strokeWidth: 2
            strokeColor: "transparent"
            startX: 50; startY: 0

            fillGradient: RadialGradient {
                id: gradient
                property real pos: 0.3
                centerX: 50;
                centerY: 50
                centerRadius: 50
                focalX: centerX; focalY: centerY
                GradientStop { position: 0; color: "#33ffbb" }
                GradientStop { position: 0.2; color: "#33ffbb" }
                GradientStop { position: 0.25; color: "transparent" }
                GradientStop { position: gradient.pos - 0.1; color: "transparent" }
                GradientStop { position: gradient.pos; color: "#33ffbb" }
                GradientStop { position: gradient.pos + 0.1; color: "transparent" }
            }
            PathArc {
                x: 50
                y: 100
                radiusX: 50
                radiusY: 50
                useLargeArc: true
            }
            PathArc {
                x: 50
                y: 0
                radiusX: 50
                radiusY: 50
                useLargeArc: true
            }
        }

        PropertyAnimation {
            target: gradient
            property: "pos"
            from: 0.3
            to: 0.9
            duration: 1500
            loops: Animation.Infinite
            easing.type: Easing.OutQuad
            running: true
        }
    }
}

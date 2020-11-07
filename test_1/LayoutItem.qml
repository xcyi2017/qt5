import QtQuick 2.0

DarkSquare {
    id: root
    width: 300
    height: 300

    Grid {
        id: grid
        anchors.centerIn: parent
        spacing: 8

        rows: 3
        columns: 3

        GreenSquare {
            BlueSquare {
                width: 12
                anchors.fill: parent
                anchors.margins: 8
                text: '(1)'
                }
            }


        GreenSquare {
            BlueSquare {
                width: 12
                y: 8
                anchors.left: parent.left
                anchors.leftMargin: 8
                text: '(2)'
            }
        }

        GreenSquare {
            BlueSquare {
                width: 48
                anchors.left: parent.right
                text: '(3)'
            }
        }


        GreenSquare {
            BlueSquare {
                id: blue1
                width: 48; height: 24
                y: 8
                anchors.horizontalCenter: parent.horizontalCenter
            }

            BlueSquare {
                id: blue2
                width: 72; height: 24
                anchors.top: blue1.bottom
                anchors.topMargin: 4
                anchors.horizontalCenter: parent.horizontalCenter
                text: '(4)'
            }
        }

        GreenSquare{
            BlueSquare {
                width: 48
                anchors.centerIn: parent
                text: '(5)'
            }
        }

        GreenSquare {
            BlueSquare {
                width: 48
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.horizontalCenterOffset: -12
                anchors.verticalCenter: parent.verticalCenter
                text: '(6)'
            }
        }
    }
}

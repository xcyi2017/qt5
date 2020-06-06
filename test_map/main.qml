import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Window 2.0
import QtPositioning 5.6
import QtLocation 5.6

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    ScrollView {
        anchors.fill: parent

        ListView {
            width: parent.width
            model: 10
            delegate: ItemDelegate {
                text: "Item " + (index + 1)
                width: parent.width
            }
        }
    }


        Plugin {
            id: mapPlugin
            name: "osm"
        }

        Map {
                id: mapview
                anchors.fill: parent
                plugin: mapPlugin
                center: QtPositioning.coordinate(59.91, 10.75)
                zoomLevel: 14

                MapItemView{
                    model: markerModel
                    delegate: mapcomponent
                }
            }

            Component {
                id: mapcomponent
                MapQuickItem {
                    id: marker
                    anchorPoint.x: image.width/4
                    anchorPoint.y: image.height
                    coordinate: position

                    sourceItem: Image {
                        id: image
                        source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
                    }
                }
            }

            MouseArea {
                anchors.fill: parent

                onPressAndHold:  {
                    var coordinate = mapview.toCoordinate(Qt.point(mouse.x,mouse.y))
                    markerModel.addMarker(coordinate)
                }
            }
        }






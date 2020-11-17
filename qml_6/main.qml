import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    // DialogButtonBox

//    Row {
//        DialogButtonBox {
//            standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel
//            onAccepted: console.log("Ok clicked")
//            onRejected: console.log("Cancel clicked")
//        }

//        DialogButtonBox {
//            Button {
//                text: qsTr("Save")
//                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
//            }
//            Button {
//                text: qsTr("Close")
//                DialogButtonBox.buttonRole: DialogButtonBox.DestructiveRole
//            }
//        }
//    }

    // Cantainer
    Row {
        anchors.fill: parent
        TabBar {
            id:tabBar

            currentIndex: 0

            width: parent.width - addButton.width - btnDelete.width

            TabButton {
                text: qsTr("TabButton")
            }
        }

        Component {
            id: tabButton
            TabButton {
                text: qsTr("TabButton")
            }
        }

        Button {
            id: addButton
            text: qsTr("+")
            flat: true
            onClicked: {
                tabBar.addItem(tabButton.createObject(tabBar))
                console.log("add: ", tabBar.itemAt(tabBar.count-1))
            }
        }

        Button {
            id: btnDelete
            text: qsTr("-")
            flat: true
            onClicked: {
                tabBar.removeItem(tabBar.itemAt(tabBar.count - 1));
            }
        }
    }
}

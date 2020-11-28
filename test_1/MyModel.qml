import QtQuick 2.0
import QtQuick.LocalStorage 2.12
import "DataBase.js" as JS


ListModel {
    id: listModel

    Component.onCompleted: {
        JS.dbReadAll();
    }
}

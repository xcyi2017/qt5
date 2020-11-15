import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 380
    title: qsTr("Hello World")

//    ClickableImageV3 {
//        id:rocket1
//        x: 40
//        y: 200
//        text: "animation on property"
//        source: "rocket.png"


//        NumberAnimation on y{
//            to: 40
//            duration: 4000
//        }


//    }

//    ClickableImageV3 {
//        id:rocket2
//        x: 152
//        y: 200
//        text: "behavior on property"
//        source: "rocket.png"

//        Behavior on y {

//            NumberAnimation { duration: 1000 }

//        }

//        Behavior on x {

//            NumberAnimation { duration: 1000 }

//        }

//        onClicked: {
//            x=40+Math.random() * (205 - 40)
//            y=40+Math.random() * (205 - 40)
//        }
//    }



//    ClickableImageV3 {
//        id:rocket3
//        x: 264
//        y: 200
//        text: "standalone animation"
//        source: "ufo.png"



//        NumberAnimation {
//            id: anim
//            target: rocket3
//            properties: "y"
//            from: 205
//            to: 40
//            duration: 1000
//        }


//        onClicked: {
//            anim.restart()
//        }
//    }

    BouncingBallExample {}
}

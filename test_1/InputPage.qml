import QtQuick 2.0
import QtQuick.Controls 2.12
import "DataBase.js" as JS
Page {
    property int rowHeight: 40
    property int rowSpacing: 8
    property int editRowId: 0
    property int editIndex: 0

    function showClassNameError() {
        className.visible = false;
        classNameError.visible = true;
    }

    function hideClassNameError() {
        className.visible = true;
        classNameError.visible = false;
    }

    function showTeacherNameError() {
        classTeacherName.visible = false;
        teacherNameError.visible = true;
    }

    function hideTeacherNameError() {
        classTeacherName.visible = true;
        teacherNameError.visible = false;
    }
    Column {
        anchors.fill: parent
        spacing: 10

        Row { // 班级
            width: parent.width
            height: rowHeight
            spacing: rowSpacing
            anchors.horizontalCenter: parent.horizontalCenter
            Label {
                text: "班级名称"
                width: parent.width * 0.3
                height: parent.height
                verticalAlignment: className.verticalAlignment
                horizontalAlignment: Text.AlignRight
            }
            TextField {
                id: className
                placeholderText: "请输入班级名称"
                width: parent.width * 0.6
                height: parent.height
            }

            Rectangle {
                id: classNameError
                visible: false
                width: parent.width * 0.6
                height: parent.height
                color: "lightgray"
                Label {
                    text: "班级名称不能为空"
                    anchors.centerIn: parent
                    color: "red"
                    clip: true // 字的裁剪
                    width: Math.min(parent.width, contentWidth)
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        hideClassNameError();
                    }
                }


                NumberAnimation on width {
                    running: classNameError.visible
                    from: 0
                    to: parent.width * 0.6
                    duration: 500
                }
            }
        }

        Row { // 班主任
            width: parent.width
            height: rowHeight
            spacing: rowSpacing
            anchors.horizontalCenter: parent.horizontalCenter
            Label {
                text: "班级老师"
                width: parent.width * 0.3
                height: parent.height
                verticalAlignment: classTeacherName.verticalAlignment
                horizontalAlignment: Text.AlignRight
            }
            TextField {
                id: classTeacherName
                placeholderText: "请输入班级老师"
                width: parent.width * 0.6
                height: parent.height
            }

            Rectangle {
                id: teacherNameError
                visible: false
                width: parent.width * 0.6
                height: parent.height
                color: "lightgray"
                Label {
                    text: "老师名称不能为空"
                    anchors.centerIn: parent
                    color: "red"
                    clip: true // 字的裁剪
                    width: Math.min(parent.width, contentWidth)
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        hideTeacherNameError();
                    }
                }


                NumberAnimation on width {
                    running: teacherNameError.visible
                    from: 0
                    to: parent.width * 0.6
                    duration: 500
                }
            }
        }

        Row {

            width: parent.width
            height: rowHeight
            spacing: rowSpacing
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                width: parent.width * 0.9 - btn1.width * 4 - rowSpacing * 3
            }

            Button {
                id: btn1
                text: "新增"
                width: parent.width * 0.15
                height: parent.height
                onClicked: {
                    if (className.length === 0) {
                        showClassNameError();
                        return;
                    }
                    if (classTeacherName.length === 0) {
                        showTeacherNameError();
                        return;
                    }
                    var rowId = parseInt(JS.dbInsert(className.text, classTeacherName.text));
                    if (rowId) {
                        mylistview.model.insert(0, {id: rowId,
                                                    name: className.text,
                                                    teacher: classTeacherName.text});
                        mylistview.currentIndex = 0;
                    }

                }
            }

            Button {
                id: btn2
                text: "保存"
                enabled: false
                width: parent.width * 0.15
                height: parent.height
                onClicked: {
                    if (className.length === 0) {
                        showClassNameError();
                        return;
                    }
                    if (classTeacherName.length === 0) {
                        showTeacherNameError();
                        return;
                    }
                    btn1.enabled = true
                    btn2.enabled = false
                    btn3.enabled = true
                    btn4.enabled = true
                    JS.dbUpdate(className.text, classTeacherName.text, editRowId); // 保存在数据库中
                    mylistview.model.setProperty(editIndex, "name", className.text);
                    mylistview.model.setProperty(editIndex, "teacher", classTeacherName.text);
                }
            }

            Button {
                id: btn3
                text: "编辑"
                width: parent.width * 0.15
                height: parent.height
                onClicked: {
                    btn1.enabled = false
                    btn2.enabled = true
                    btn3.enabled = false
                    btn4.enabled = false
                    editRowId = mylistview.model.get(mylistview.currentIndex).id; // 数据库中的id
                    editIndex = mylistview.currentIndex; // mylistview中的index

                    className.text = mylistview.model.get(editIndex).name;
                    classTeacherName.text = mylistview.model.get(editIndex).teacher;
                }
            }

            Button {
                id: btn4
                text: "删除"
                width: parent.width * 0.15
                height: parent.height
                onClicked: {
                    JS.dbDeleteRow(mylistview.model.get(mylistview.currentIndex).id);
                    mylistview.model.remove(mylistview.currentIndex, 1);
                    if (mylistview.count === 0) {
                        mylistview.currentIndex = -1;
                    }
                }
            }

        }
    }
}

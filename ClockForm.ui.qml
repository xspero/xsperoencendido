import QtQuick 2.7

Rectangle {
    property alias date: dateText.text
    property alias time: timeText.text
    property alias day: dayText.text

    width: 329
    height: 274
    color: "#0e0d0d"
    radius: 21
    border.width: 3
    border.color: "#94a5c7"
    anchors.topMargin: 103
    anchors.leftMargin: 236
    anchors.left: parent.left
    anchors.top: parent.top

    Text {
        id: dateText
        color: "#3a80a5"
        text: "2016-04-06"
        anchors.horizontalCenterOffset: 0
        anchors.topMargin: 2
        //font.family: mainFont.name
        font.pixelSize: 49
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: timeText
        x: 39
        y: 37
        color: "#3a80a5"
        text: "19:49"
        //font.family: mainFont.name
        font.pixelSize: 115
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        wrapMode: Text.WordWrap
    }

    Text {
        id: dayText

        color: "#3a80a5"
        text: "Wednesday"
        //font.family: mainFont.name
        font.pixelSize: 36
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
    }
}

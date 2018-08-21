import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtMultimedia 5.8
import QtQuick.Dialogs 1.0
import QtQuick.Window 2.3
import QtMediaPlayer 1.0

ApplicationWindow {
    id:windwowid
    visible: true
    width: 640
    height: 480
    title: qsTr("Video Player")

    FileDialog {
         id: fileDialog
         title: "Please choose a file"
         folder: shortcuts.home
         onAccepted: {
             console.log("You chose: " + fileDialog.fileUrls)
             var path = "" + fileDialog.fileUrl
             var fileName = path.replace("file:///", "")
             console.log("fileName: " + fileName)
             qtmediaplayer.fileName = fileName
             qtmediaplayer.play()
         }
         onRejected: {
             console.log("Canceled")
         }
         Component.onCompleted: visible = true
     }
    Rectangle{
        id:rect
        visible: true
        anchors.fill: parent
        color: Qt.rgba(0,1,1,0)

    QtMediaPlayer{
        id:qtmediaplayer
//        videoWidget: windwowid
    }

    VideoOutput {
        id: videooutput
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: qtmediaplayer
        focus : visible

        ColorAnimation {
            from: "white"
            to: "black"
            duration: 200
        }

    }
    Button{
        id:button
        text: qsTr("点击播放")
        onClicked: {
//            qtmediaplayer.fileName = "C:/myfile.mp4"
            qtmediaplayer.ready()
            qtmediaplayer.playbackRate = 1
            console.log(qtmediaplayer.position,"position","media:",qtmediaplayer.getVideoSurface())
        }
    }
    Label {
        id:             runningTime
        text:           runningTime.msToTime(qtmediaplayer.position)
        visible:        true
        anchors.top:    parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        function msToTime(s) {
            function pad(n, z) {
                z = z || 2;
                return ('00' + n).slice(-z);
            }
            var ms = s % 1000;
            s = (s - ms) / 1000;
            var secs = s % 60;
            s = (s - secs) / 60;
            var mins = s % 60;
            var hrs = (s - mins) / 60;
            return pad(hrs) + ':' + pad(mins) + ':' + pad(secs) + '.' + pad(ms, 3);
        }
        onTextChanged: {
            console.log("text change..",runningTime.text)
//            console.log(qtmediaplayer.PlayingState,MediaPlayer.PlayingState)
//            if(qtmediaplayer.PlayingState === MediaPlayer.PlayingState)
            progressBar.value = qtmediaplayer.position
        }
    }
    Slider {
        id: progressBar
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.rightMargin: -6
        anchors.leftMargin: -6
        anchors.bottomMargin: -6
        value: 0
        from: 0
        stepSize: 1
        snapMode: Slider.SnapOnRelease
        to: qtmediaplayer.duration
        onValueChanged: {
            console.log("progress value change..",progressBar.value)
//            if(qtmediaplayer.PlayingState != MediaPlayer.PlayingState)
//                qtmediaplayer.setPosition(value)
        }
        onPressedChanged: {
            qtmediaplayer.pause()
            qtmediaplayer.play()
        }
    }
  }
}

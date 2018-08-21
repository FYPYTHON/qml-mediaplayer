QT += quick widgets opengl gamepad xml svg qml
QT += core gui widgets multimediawidgets multimedia
CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
        main.cpp \
    qtmediaplayer.cpp

RESOURCES += qml.qrc


QML_IMPORT_PATH =

#QML_AAA = 0

QML_DESIGNER_IMPORT_PATH =

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    qtmediaplayer.h

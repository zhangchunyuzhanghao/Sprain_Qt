#-------------------------------------------------
#
# Project created by QtCreator 2020-03-02T11:21:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLC-QT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# VLC-Qt SDK
VLC_Qt_SDK_PATH = $$PWD/VLC-Qt_1.1.0_win64_msvc2015

CONFIG(debug, debug|release) {
    LIBS += -L$$VLC_Qt_SDK_PATH/lib -lVLCQtCored -lVLCQtWidgetsd
} else {
    LIBS += -L$$VLC_Qt_SDK_PATH/lib -lVLCQtCore -lVLCQtWidgets
}

INCLUDEPATH += $$VLC_Qt_SDK_PATH/include


SOURCES += \
        main.cpp \
    custom/basewidget.cpp \
    custom/vlc_seek_slider.cpp \
    vlc_app.cpp \
    custom/vlc_setting.cpp

FORMS +=

HEADERS += \
    custom/basewidget.h \
    custom/vlc_seek_slider.h \
    vlc_config.h \
    vlc_app.h \
    custom/vlc_setting.h \
    utils/commonhelper.h

RESOURCES += \
    res/res.qrc

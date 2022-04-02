#-------------------------------------------------
#
# Project created by QtCreator 2017-05-01T11:45:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRCoder
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

include(./QZXing/QZXing.pri)

RESOURCES += \
    res.qrc

SUBDIRS += \
    QZXing/QZXing.pro

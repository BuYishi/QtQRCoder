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

DISTFILES += \
    QZXing/eabi/QZXingu.def \
    QZXing/qtc_packaging/debian_fremantle/compat \
    QZXing/qtc_packaging/debian_fremantle/control \
    QZXing/qtc_packaging/debian_fremantle/copyright \
    QZXing/qtc_packaging/debian_harmattan/compat \
    QZXing/qtc_packaging/debian_harmattan/control \
    QZXing/qtc_packaging/debian_harmattan/copyright \
    QZXing/qtc_packaging/debian_harmattan/manifest.aegis \
    QZXing/QZXing_resource.rc \
    QZXing/qtc_packaging/debian_fremantle/changelog \
    QZXing/qtc_packaging/debian_harmattan/changelog \
    QZXing/zxing/bigint/ChangeLog \
    QZXing/qtc_packaging/debian_fremantle/rules \
    QZXing/qtc_packaging/debian_harmattan/rules \
    QZXing/qtc_packaging/debian_fremantle/README \
    QZXing/qtc_packaging/debian_harmattan/README \
    QZXing/zxing/bigint/README

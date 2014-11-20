#-------------------------------------------------
#
# Project created by QtCreator 2014-11-20T17:42:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InfDevice
TEMPLATE = app


SOURCES += main.cpp\
        infdevice.cpp \
    cpuid.cpp

HEADERS  += infdevice.h \
    cpuid.h

FORMS    += infdevice.ui

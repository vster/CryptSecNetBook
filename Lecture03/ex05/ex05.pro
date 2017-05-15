TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex05.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

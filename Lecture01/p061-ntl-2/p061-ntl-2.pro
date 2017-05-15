TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    matrix02.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl



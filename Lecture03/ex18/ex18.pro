TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex18.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

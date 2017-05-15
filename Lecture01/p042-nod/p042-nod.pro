TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    nod.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

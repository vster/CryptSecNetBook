TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p139.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

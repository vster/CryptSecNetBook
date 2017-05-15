TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex21.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

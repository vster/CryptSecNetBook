TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex20.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

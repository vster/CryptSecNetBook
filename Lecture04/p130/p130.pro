TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p130.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

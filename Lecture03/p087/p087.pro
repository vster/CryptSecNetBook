TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p087-afin-ca.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

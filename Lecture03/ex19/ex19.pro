TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex19.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p133.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

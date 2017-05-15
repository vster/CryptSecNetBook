TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex26.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

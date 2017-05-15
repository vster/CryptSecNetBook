TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex24.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

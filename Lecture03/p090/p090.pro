TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p090.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

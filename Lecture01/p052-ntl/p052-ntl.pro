TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p052.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    nod-e.cpp

INCLUDEPATH += \
    ../../include

LIBS += \
    -L../../lib -lntl

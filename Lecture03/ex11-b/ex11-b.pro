TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex11-b.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

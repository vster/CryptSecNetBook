TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p133-1.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

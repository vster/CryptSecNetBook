TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p134.cpp

INCLUDEPATH += \
    ../../../include

LIBS += \
    -L../../../lib -lntl

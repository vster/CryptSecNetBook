TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p135.cpp

INCLUDEPATH += \
    ../../include

LIBS += \
    -L../../lib -lntl

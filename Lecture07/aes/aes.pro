TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    aes.cpp \
    util.cpp

HEADERS +=

INCLUDEPATH += \
    ../../../include ../../include

LIBS += \
    -L../../../lib -lntl

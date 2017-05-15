TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    aes-main.cpp \
    aes.cpp \
    util.cpp

HEADERS += \
    aes.h \
    vchtest.h

INCLUDEPATH += \
    ../../../include ../../include

LIBS += \
    -L../../../lib -lntl

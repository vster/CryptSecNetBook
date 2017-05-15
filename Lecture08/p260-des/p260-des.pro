TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    des-main.cpp \
    des.cpp \
    util.cpp

HEADERS += \
    des.h \
    vchtest.h

INCLUDEPATH += \
    ../../include

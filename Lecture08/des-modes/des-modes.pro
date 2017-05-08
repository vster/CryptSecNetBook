TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    des.cpp \
    util.cpp \
    des-main.cpp

HEADERS += \
    des.h \
    vchtest.h \
    ../../include/util.h

INCLUDEPATH += \
    ../../include

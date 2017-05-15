TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    aes-main.cpp \
    aes.cpp \
    util.cpp \
    amodes.cpp

HEADERS += \
    aes.h \
    vchtest.h \
    amodes.h

INCLUDEPATH += \
    ../../../include ../../include

LIBS += \
    -L../../../lib -lntl

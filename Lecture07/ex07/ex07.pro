TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    aes-main.cpp \
    aes.cpp \
    util.cpp

HEADERS += \
    aes.h

INCLUDEPATH += \
    ../../../include ../../include

LIBS += \
    -L../../../lib -lntl

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    util.cpp \
    ex11.cpp

HEADERS += \
    aes.h \
    ex11.h

INCLUDEPATH += \
    ../../../include ../../include

LIBS += \
    -L../../../lib -lntl

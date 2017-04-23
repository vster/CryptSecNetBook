TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p228.cpp \
    util.cpp

INCLUDEPATH += \
    ../../../include ../../include

LIBS += \
    -L../../../lib -lntl

HEADERS +=

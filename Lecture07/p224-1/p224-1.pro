TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p224-1.cpp

INCLUDEPATH += \
    ../../include

LIBS += \
    -L../../lib -lntl

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex25.cpp

INCLUDEPATH += \
    /usr/local/include

LIBS += \
    -lntl -lgmp

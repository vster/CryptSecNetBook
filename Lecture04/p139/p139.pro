TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p139.cpp

LIBS += \
    -L/usr/local/lib -lntl -lgmp

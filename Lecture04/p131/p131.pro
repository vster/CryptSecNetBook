TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p131.cpp

LIBS += \
    -L/usr/local/lib -lntl -lgmp

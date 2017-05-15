TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex25.cpp

LIBS += \
    -L/usr/local/lib -lntl -lgmp

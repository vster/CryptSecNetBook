TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p087-afin-ca.cpp

INCLUDEPATH += \
    /usr/local/include

LIBS += \
    -L/usr/local/lib -lntl \
    -lgmp

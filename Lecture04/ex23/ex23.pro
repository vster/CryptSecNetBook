TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex23.cpp

INCLUDEPATH += \
    /usr/local/include

LIBS += \
    -L/usr/local/lib -lntl \
    -lgmp
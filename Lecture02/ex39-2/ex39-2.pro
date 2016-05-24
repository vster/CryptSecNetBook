TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex39-2.cpp

INCLUDEPATH += \
    ../../../WinNTL-9_8_1/include

LIBS += \
    -L../../../WinNTL-9_8_1/lib -lntl

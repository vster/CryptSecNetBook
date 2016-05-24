TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ex38-1.cpp

INCLUDEPATH += \
    ../../../WinNTL-9_8_1/include

LIBS += \
    -L../../../WinNTL-9_8_1/lib -lntl

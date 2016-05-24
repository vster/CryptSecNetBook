TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    nod-e.cpp

INCLUDEPATH += \
    ../../../WinNTL-9_8_1/include

LIBS += \
    -L../../../WinNTL-9_8_1/lib -lntl

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    gmodes.cpp \
    gost.cpp \
    util.cpp \
    main.cpp

HEADERS += \
    gmodes.h \
    gost.h \
    vchtest.h \
    util.h

INCLUDEPATH += \
    ../../include

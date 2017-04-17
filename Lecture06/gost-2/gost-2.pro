TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    gost.cpp \
    util.cpp \
    main.cpp

HEADERS += \
    gost.h \
    vchtest.h

INCLUDEPATH += \
    ../../include

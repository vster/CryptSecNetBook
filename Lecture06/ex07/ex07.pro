TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    util.cpp \
    des.cpp \
    main.cpp

HEADERS += \
    des.h \
    ../../include/util.h

INCLUDEPATH += \
    ../../include


TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        2b.cpp \
        GaussLegendreQuadrature.cpp \
        lib.cpp \
        main.cpp

HEADERS += \
    GaussLegendreQuadrature.h \
    lib.h

DISTFILES += \
    example.txt \
    main

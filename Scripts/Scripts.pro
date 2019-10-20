TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        3b.cpp \
        GaussLegendreQuadrature.cpp \
        gauss-laguerre.cpp \
        lib.cpp \
        main.cpp

HEADERS += \
    GaussLegendreQuadrature.h \
    gauss-laguerre.h \
    lib.h

DISTFILES += \
    main

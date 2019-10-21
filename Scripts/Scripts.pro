TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        2b.cpp \
        GaussLaguerre.cpp \
        GaussLegendreQuadrature.cpp \
        gauss-legendre.cpp \
        lib.cpp \
        main.cpp

HEADERS += \
    GaussLaguerre.h \
    GaussLegendreQuadrature.h \
    lib.h

DISTFILES += \
    example.txt \
    main

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp

SOURCES += \
        2b.cpp \
        GaussLegendreQuadrature.cpp \
        MonteCarlo.cpp \
        MonteCarloImproved.cpp \
        lib.cpp \
        main.cpp

HEADERS += \
    GaussLegendreQuadrature.h \
    MonteCarlo.h \
    MonteCarloImproved.h \
    lib.h

DISTFILES += \
    example.txt \
    main

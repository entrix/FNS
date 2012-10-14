#-------------------------------------------------
#
# Project created by QtCreator 2012-07-25T23:00:55
#
#-------------------------------------------------

QT       += core gui

TARGET = FiniteDifference
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    twoDimensional/iterationscheme.cpp \
    lattice.cpp \
    schemeexception.cpp \
    twoDimensional/simpleiterationscheme.cpp

HEADERS  += mainwindow.h \
    twoDimensional/iterationscheme.h \
    lattice.h \
    schemeexception.h \
    twoDimensional/simpleiterationscheme.h

FORMS    += mainwindow.ui

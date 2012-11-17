#-------------------------------------------------
#
# Project created by QtCreator 2012-11-07T13:30:21
#
#-------------------------------------------------

QT       += core gui
QT       += xml
CONFIG += debug

# Setter flagg for c++ kompilator, setter standard til c++11,
# streng feilsjekking
# QMAKE_CXXFLAGS= -std=c++0x -W -Wall -pedantic

TARGET = GitApplikasjon
TEMPLATE = app


SOURCES +=\
    main.cpp \
    contact.cpp \
    event.cpp \
    eventhandler.cpp \
    contacthandler.cpp \
    troller.cpp \
    contactview.cpp \
    eventview.cpp \
    extendedqcalendar.cpp \
    calendarview.cpp \
    filewriter.cpp

HEADERS  += \
    contact.h \
    event.h \
    eventhandler.h \
    contacthandler.h \
    troller.h \
    contactview.h \
    eventview.h \
    extendedqcalendar.h \
    calendarview.h \
    filewriter.h

FORMS    += mainwindow.ui

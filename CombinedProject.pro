#-------------------------------------------------
#
# Project created by QtCreator 2018-06-28T19:56:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CombinedProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        stringmath.cpp \
        basiccalculator.cpp \
    button.cpp \
    matrixcalculator.cpp \
    equationcalculator.cpp \
    getdeterminant.cpp \
    programmercalculator.cpp \
    numberconversion.cpp \
    financialcalculator.cpp \
    scientificcalculator.cpp \
    getfactorial.cpp \
    reversestring.cpp \
    manualmode.cpp \
    formulamode.cpp \
    aboutmode.cpp \
    conversioncalculator.cpp

HEADERS += \
        basiccalculator.h \
        mainwindow.h \
        stringmath.h \
    button.h \
    matrixcalculator.h \
    equationcalculator.h \
    getdeterminant.h \
    programmercalculator.h \
    numberconversion.h \
    financialcalculator.h \
    scientificcalculator.h \
    getfactorial.h \
    reversestring.h \
    manualmode.h \
    formulamode.h \
    aboutmode.h \
    conversioncalculator.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    images.qrc

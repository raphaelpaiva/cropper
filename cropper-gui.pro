#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T10:51:30
#
#-------------------------------------------------

QT       += core gui

TARGET = cropper-gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    command/command.cpp \
    command/resize.cpp \
    command/scale.cpp \
    command/commandexception.cpp \
    image_processing/imageprocessor.cpp \
    command/crop.cpp \
    command/rotate.cpp \
    command/mirror.cpp \
    command/lightness.cpp

HEADERS  += mainwindow.h\
    command/command.h \
    command/resize.h \
    command/scale.h \
    command/commandexception.h \
    image_processing/imageprocessor.h \
    command/crop.h \
    command/rotate.h \
    command/mirror.h \
    command/lightness.h

FORMS    += mainwindow.ui

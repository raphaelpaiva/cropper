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
        command/cropper.cpp \
    command/command.cpp \
    command/resize.cpp \
    command/scale.cpp \
    command/commandexception.cpp

HEADERS  += mainwindow.h\
            command/cropper.h \
    command/command.h \
    command/resize.h \
    command/scale.h \
    command/commandexception.h

FORMS    += mainwindow.ui

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
    command/lightness.cpp \
    command/interpolatedscale.cpp \
    command/interpolated3.cpp \
    command/invertcolors.cpp \
    command/grayscale.cpp \
    command/popart.cpp \
    command/crazy.cpp \
    command/merge.cpp \
    command/append.cpp \
    command/mask.cpp \
    command/sepia.cpp \
    command/xray.cpp \
    command/fliphorizontal.cpp \
    command/flipvertical.cpp \
    command/makeit3d.cpp \
    command/rotate2.cpp

HEADERS  += mainwindow.h\
    command/command.h \
    command/resize.h \
    command/scale.h \
    command/commandexception.h \
    image_processing/imageprocessor.h \
    command/crop.h \
    command/rotate.h \
    command/mirror.h \
    command/lightness.h \
    command/interpolatedscale.h \
    command/interpolated3.h \
    command/invertcolors.h \
    command/grayscale.h \
    command/popart.h \
    command/crazy.h \
    command/merge.h \
    command/append.h \
    command/mask.h \
    command/sepia.h \
    command/xray.h \
    command/fliphorizontal.h \
    command/flipvertical.h \
    command/makeit3d.h \
    command/rotate2.h

FORMS    +=

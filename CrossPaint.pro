#-------------------------------------------------
#
# Project created by QtCreator 2014-08-12T22:02:38
#
#-------------------------------------------------

QT       += core opengl widgets

TARGET = CrossPaint
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    brush.cpp \
    configuregriddialog.cpp \
    configureimagedialog.cpp \
    cursor.cpp \
    drawwidget.cpp \
    grid.cpp \
    image.cpp \
    layer.cpp \
    mainwindow.cpp \
    pixel.cpp \
    restriction.cpp \
    tool.cpp \
    types.cpp \
    drawview.cpp

HEADERS += \
    brush.h \
    configuregriddialog.h \
    configureimagedialog.h \
    cursor.h \
    drawwidget.h \
    grid.h \
    image.h \
    layer.h \
    mainwindow.h \
    pixel.h \
    restriction.h \
    tool.h \
    types.h \
    drawview.h

OTHER_FILES += \
    CrossPaint.pro.user

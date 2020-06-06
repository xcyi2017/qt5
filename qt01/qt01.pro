#-------------------------------------------------
#
# Project created by QtCreator 2019-08-27T12:33:19
#
#-------------------------------------------------

# 模块
QT       += core gui
# 高于4版本，添加 QT += widgets, 为了就按容Qt4
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 应用程序名字
TARGET = qt01
# 指定qt01的类型
TEMPLATE = app

# 源文件
SOURCES += main.cpp\
        mainwindow.cpp
# 头文件
HEADERS  += mainwindow.h

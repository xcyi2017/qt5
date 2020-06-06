TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += shell.c sqlite3.c
HEADERS += sqlite3.h sqlite3ext.h

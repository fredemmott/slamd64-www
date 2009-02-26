TEMPLATE = app
TARGET = 
QT -= gui
QT += sql xmlpatterns
CONFIG += debug

LIBS += -lFastCgiQt

# Input
HEADERS += StaticPagesService.h Slamd64Website.h
SOURCES += StaticPagesService.cpp Slamd64Website.cpp main.cpp

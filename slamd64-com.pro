TEMPLATE = app
TARGET = 
QT -= gui
QT += sql xmlpatterns
CONFIG += debug

LIBS += -lFastCgiQt

# Input
HEADERS += DatabaseProvider.h NewsService.h StaticPagesService.h Slamd64Website.h
SOURCES += DatabaseProvider.cpp NewsService.cpp StaticPagesService.cpp Slamd64Website.cpp main.cpp

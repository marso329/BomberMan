QT += core gui widgets sql multimedia
TARGET = template
TEMPLATE = app

CONFIG += qt
CONFIG += 

QMAKE_CXXFLAGS += -g -std=c++11 -pedantic -Werror -Wall

OBJ_DIR = ../build
OBJECTS_DIR = ../build
MOC_DIR = ../build
DESTDIR = ../bin
INCLUDEDIR=../include
RESOURCEDIR=../resources
SRCDIR=../src
UI_DIR = ../include

SOURCES +=	$$SRCDIR/piece.cpp \	
		$$SRCDIR/score.cpp \
		$$SRCDIR/game_scene.cpp \
		$$SRCDIR/sprites.cpp \
		$$SRCDIR/audio.cpp \
		$$SRCDIR/main.cpp \
		$$SRCDIR/mainwindow.cpp 
			

HEADERS +=	$$INCLUDEDIR/piece.h \	
		$$INCLUDEDIR/score.h \
		$$INCLUDEDIR/game_scene.h \
		$$INCLUDEDIR/mainwindow.h \
		$$INCLUDEDIR/audio.h \
		$$INCLUDEDIR/sprites.h

INCLUDEPATH +=./$${INCLUDEDIR}

LIBS += 

FORMS += ../ui/mainwindow.ui

RESOURCES     = $$RESOURCEDIR/resources.qrc

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += Source/main.cpp

DEFINES += SFML_STATIC

win32: LIBS += -L$$PWD/External/Library_Windows/ -lsfml-window-s -lsfml-system-s -lsfml-graphics-s -lfreetype -ljpeg -lstdc++ -lwinmm -lgdi32 -lopengl32

INCLUDEPATH += $$PWD/External/Include
DEPENDPATH += $$PWD/External/Include

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/External/Library_Windows/sfml-graphics-s.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/External/Library_Windows/libsfml-graphics-s.a

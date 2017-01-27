TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += Source/main.cpp \
    Source/Arkanoid.cpp \
    Source/Ball.cpp \
    Source/Paddle.cpp \
    Source/GDEngine/Entity.cpp \
    Source/GDEngine/GDEngine.cpp \
    Source/GDEngine/Scene.cpp \
    Source/GDEngine/SceneManager.cpp

DEFINES += SFML_STATIC

QMAKE_CXXFLAGS += -std=c++11 -Wall -Werror -Wextra -Wno-unused-but-set-variable -Wpedantic

win32: LIBS += -L$$PWD/External/Library_Windows/ -lsfml-window-s -lsfml-graphics-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg -lopenal32 -lFLAC -lvorbisfile -lvorbisenc -lvorbis -logg -lstdc++

INCLUDEPATH += $$PWD/External/Include $$PWD/Source
DEPENDPATH += $$PWD/External/Include

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/External/Library_Windows/sfml-graphics-s.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/External/Library_Windows/libsfml-graphics-s.a

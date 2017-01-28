TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += Source/main.cpp \
    Source/Game/Arkanoid.cpp \
    Source/Game/Ball.cpp \
    Source/Game/Paddle.cpp \
    Source/GDCore/Entity.cpp \
    Source/GDCore/GDCore.cpp \
    Source/GDCore/Scene.cpp \
    Source/GDCore/SceneManager.cpp \
    Source/GDCore/InputManager.cpp \
    Source/GDCore/ActionManager.cpp

DEFINES += SFML_STATIC

QMAKE_CXXFLAGS += -std=c++11 -Wall -Werror -Wextra -Wno-unused-but-set-variable -Wpedantic

win32: LIBS += -L$$PWD/External/SFML/Library_Windows/ -lsfml-window-s -lsfml-graphics-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg -lopenal32 -lFLAC -lvorbisfile -lvorbisenc -lvorbis -logg -lstdc++

INCLUDEPATH += $$PWD/External/SFML/Include $$PWD/Source
DEPENDPATH += $$PWD/External/SFML/Include

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/External/SFML/Library_Windows/sfml-graphics-s.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/External/SFML/Library_Windows/libsfml-graphics-s.a

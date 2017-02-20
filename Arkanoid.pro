TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += Source/main.cpp \
    Source/Game/Arkanoid.cpp \
    Source/Game/Ball.cpp \
    Source/Game/Paddle.cpp \
    Source/Game/TestScene.cpp \
    Source/GDCore/Entity.cpp \
    Source/GDCore/GDCore.cpp \
    Source/GDCore/Scene.cpp \
    Source/GDCore/SceneManager.cpp \
    Source/GDCore/InputManager.cpp \
    Source/GDCore/ActionManager.cpp \
    Source/Game/ButtonState.cpp \
    Source/Game/HUD.cpp \
    Source/Game/Brick.cpp

HEADERS += \
    Source/GDCore/ActionManager.h \
    Source/GDCore/Entity.h \
    Source/GDCore/GDCore.h \
    Source/GDCore/InputManager.h \
    Source/GDCore/Scene.h \
    Source/GDCore/SceneManager.h \
    Source/Game/Arkanoid.h \
    Source/Game/Ball.h \
    Source/Game/ButtonState.h \
    Source/Game/Paddle.h \
    Source/Game/TestScene.h \
    Source/Game/HUD.h \
    Source/Game/Brick.h


DEFINES += SFML_STATIC

QMAKE_CXXFLAGS += -std=c++11 #-Wall -Werror -Wextra -Wno-unused-but-set-variable -Wpedantic

win32: LIBS += -L$$PWD/External/SFML/Library_Windows/ -lsfml-window-s -lsfml-graphics-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg -lopenal32 -lFLAC -lvorbisfile -lvorbisenc -lvorbis -logg -lstdc++

INCLUDEPATH += $$PWD/External/SFML/Include $$PWD/Source
DEPENDPATH += $$PWD/External/SFML/Include

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/External/SFML/Library_Windows/sfml-graphics-s.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/External/SFML/Library_Windows/libsfml-graphics-s.a


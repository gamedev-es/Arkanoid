#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>

#include "Scene.h"

namespace GDES
{
    class SceneManager
    {
    public:
        SceneManager();
        ~SceneManager();

        Scene *currentScene;

    };
}

#endif // SCENEMANAGER_H

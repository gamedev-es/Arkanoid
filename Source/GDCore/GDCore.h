#pragma once
#ifndef GCORE_H
#define GDCORE_H

#include <iostream>
#include <string>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>

#include "SceneManager.h"
#include "Scene.h"
#include "Entity.h"
#include "InputManager.h"

namespace GDES
{
    class GDCore
    {
    public:
        GDCore(const sf::String &title, int width, int heigh, const sf::String &assetsDiretory = "Data");
        ~GDCore();

		void Initialize();
        void Run();
        void Exit();
        void SetTitle(const sf::String &title);

    private:
		GDCore();
        void Update(sf::Time elapsedTime);
        void ProcessEvents();
        void Render();
        bool exit;

        static const sf::Time TimePerFrame;
        sf::RenderWindow mWindow;

    protected:
        SceneManager sceneManager;
		InputManager inputManager;
        sf::String  assetsDirectoryRoot;

    };
}

#endif // GDCORE_H

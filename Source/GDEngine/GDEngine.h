#ifndef GDENGINE_H
#define GDENGINE_H

#include <iostream>
#include <string>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>

#include "GDEngine/SceneManager.h"
#include "GDEngine/Scene.h"
#include "GDEngine/Entity.h"



namespace GDE
{
    class GDEngine
    {
    public:
        GDEngine(const sf::String &title, int width, int heigh, const sf::String &assetsDiretory = "Data");
        ~GDEngine();

        void Run();
        void Exit();
        void SetTitle(const sf::String &title);


    private:
        void Update(sf::Time elapsedTime);
        void Render();
        bool exit;

        static const sf::Time	TimePerFrame;
        sf::RenderWindow		mWindow;

        void ProcessEvents();
        void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    protected:
        SceneManager sceneManager;
        sf::String  assetsDirectoryRoot;

    };
}

#endif // GDENGINE_H

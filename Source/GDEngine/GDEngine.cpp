#include "GDEngine.h"

namespace GDE
{
    const sf::Time GDEngine::TimePerFrame = sf::seconds(1.f/60.f);

    GDEngine::GDEngine(const sf::String &title, int width, int height, const sf::String &assetsDiretory)
        : mWindow(sf::VideoMode(width, height), title, sf::Style::Close)
    {
        this->exit = false;
        this->assetsDirectoryRoot = assetsDiretory;

    }

    void GDEngine::Run()
    {
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (mWindow.isOpen() && !exit)
        {
            sf::Time elapsedTime = clock.restart();
            timeSinceLastUpdate += elapsedTime;
            while (timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;

                ProcessEvents();
                Update(TimePerFrame);
            }

            Render();
        }
    }

    void GDEngine::ProcessEvents()
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                    HandlePlayerInput(event.key.code, true);
                    break;

                case sf::Event::KeyReleased:
                    HandlePlayerInput(event.key.code, false);
                    break;

                case sf::Event::Closed:
                    mWindow.close();
                    break;
            }
        }
    }

    void GDEngine::HandlePlayerInput(sf::Keyboard::Key, bool)
    {
    }

    void GDEngine::Update(sf::Time elapsedTime)
    {
        if (this->sceneManager.currentScene != NULL)
        {
            this->sceneManager.currentScene->Update(elapsedTime);
        }

    }

    void GDEngine::Render()
    {
        mWindow.clear();

        if (this->sceneManager.currentScene != NULL)
        {
            this->sceneManager.currentScene->Draw();
        }

        mWindow.setView(mWindow.getDefaultView());
        mWindow.display();
    }

    void GDEngine::Exit()
    {
        exit = true;
    }

    void GDEngine::SetTitle(const sf::String &title)
    {
        this->mWindow.setTitle(title);
    }

    GDEngine::~GDEngine()
    {

    }
}

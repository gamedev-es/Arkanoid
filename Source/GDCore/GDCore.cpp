#include "GDCore.h"

namespace GDES
{
	const sf::Time GDCore::TimePerFrame = sf::seconds(1.f / 60.f);

	GDCore::GDCore(const sf::String &title, int width, int height, const sf::String &assetsDiretory)
		: mWindow(sf::VideoMode(width, height), title, sf::Style::Close)
	{
		assetsDirectoryRoot = assetsDiretory;
		Initialize();
	}


	void GDCore::Initialize()
	{
		exit = false;
		mWindow.setView(mWindow.getDefaultView());
	}

	void GDCore::Run()
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

	void GDCore::ProcessEvents()
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				mWindow.close();
				break;
			default:
				GetInputManager()->HandleEvent(event);
			}
		}
	}

	void GDCore::Update(sf::Time elapsedTime)
	{
		if (GetSceneManager()->GetCurrentScene() != NULL)
		{
			GetSceneManager()->GetCurrentScene()->Update(elapsedTime);
		}

	}

	void GDCore::Render()
	{
		mWindow.clear();

		if (GetSceneManager()->GetCurrentScene() != NULL)
		{
			GetSceneManager()->GetCurrentScene()->Draw(&mWindow);
		}

		mWindow.display();
	}

	void GDCore::Exit()
	{
		exit = true;
	}

	void GDCore::SetTitle(const sf::String &title)
	{
		mWindow.setTitle(title);
	}

	GDCore::~GDCore()
	{
		InputManager* inputManager = GetInputManager();
		if (inputManager)
		{
			delete inputManager;
			inputManager = NULL;
		}

		SceneManager* sceneManager = GetSceneManager();
		if (sceneManager)
		{
			delete sceneManager;
			sceneManager = NULL;
		}
	}
}

#pragma once
#ifndef GCORE_H
#define GDCORE_H

#include <iostream>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Time.hpp>

#include "IEntity.h"
#include "Scene.h"
#include "SceneManager.h"

namespace GDES {
	class GDCore {
	public:
		GDCore(const sf::String& title, int width, int height, const sf::String& assetsDiretory = "Data");
		virtual ~GDCore() = default;

		void Initialize();
		void Run();
		void Exit();
		void SetTitle(const sf::String& title);

		// Singleton
		static SceneManager* GetSceneManager() {
			static SceneManager* sceneManager = new SceneManager();
			return sceneManager;
		}

	private:
		GDCore();
		void Update(sf::Time elapsedTime);
		void ProcessEvents();
		void Render();
		bool exit;

		static const sf::Time TimePerFrame;
		std::unique_ptr<sf::RenderWindow> mWindow;

	protected:
		sf::String assetsDirectoryRoot;
		sf::String title;
		int width;
		int height;
	};
}

#endif // GDCORE_H

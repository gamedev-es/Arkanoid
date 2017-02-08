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

		bool AddScene(int sceneIndex, Scene* scene, bool isCurrentScene = false);
		bool LoadScene(int sceneIndex);
		bool RemoveScene(int sceneIndex, bool removeFromMemory);
		Scene* GetScene(int sceneIndex);
		Scene* GetCurrentScene() { return currentScene; }
	private:
		Scene *currentScene;
		std::map<int, Scene*> sceneMap;
	};
}

#endif // SCENEMANAGER_H

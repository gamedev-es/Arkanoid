#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <map>
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

#pragma once

#include "Scene.h"
#include <string>
#include <map>

namespace GDES {
	class SceneManager {
	public:
		SceneManager() = default;
		~SceneManager();

		bool AddScene(std::shared_ptr<Scene> scene, bool isCurrentScene = false);
		bool LoadScene(const std::string& sceneName);
		bool RemoveScene(const std::string& sceneName, bool removeFromMemory);
		std::shared_ptr<Scene> GetScene(const std::string& sceneName);
		std::shared_ptr<Scene> GetCurrentScene() { return currentScene; }

	private:
		std::shared_ptr<Scene> currentScene{ nullptr };
		std::map<std::string, std::shared_ptr<Scene>> sceneMap;
	};
}

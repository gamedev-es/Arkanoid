#include "SceneManager.h"

namespace GDES {
	SceneManager::~SceneManager() {
		for (auto& s : sceneMap) {
			std::shared_ptr<Scene> scene = s.second;
			scene.reset();
		}
		sceneMap.clear();
	}

	bool SceneManager::AddScene(std::shared_ptr<Scene> scene, bool isCurrentScene) {
		if (!scene) {
			return false;
		}

		sceneMap.insert(std::make_pair(scene->GetName(), scene));

		if (isCurrentScene) {
			currentScene = scene;
			currentScene->Initialize();
		}

		return true;
	}

	bool SceneManager::LoadScene(std::string sceneName) {
		std::map<std::string, std::shared_ptr<Scene>>::iterator it = sceneMap.find(sceneName);

		if (it == sceneMap.end()) {
			return false; // No existe esa escena
		}

		currentScene = it->second;

		currentScene->Initialize();

		return true;
	}

	bool SceneManager::RemoveScene(std::string sceneName, bool removeFromMemory) {
		std::map<std::string, std::shared_ptr<Scene>>::iterator it = sceneMap.find(sceneName);

		if (it == sceneMap.end()) {
			return false; // No existe esa escena
		}

		// Lo dejamos opcional en caso que no se quiera borrar la scene
		// solo quitarlo del listado
		if (removeFromMemory) {
			std::shared_ptr<Scene> scene = it->second;
			scene.reset();
		}

		sceneMap.erase(it);

		return true;
	}

	std::shared_ptr<Scene> SceneManager::GetScene(std::string sceneName) {
		std::map<std::string, std::shared_ptr<Scene>>::iterator it = sceneMap.find(sceneName);

		if (it == sceneMap.end()) {
			return NULL; // No existe esa escena
		}

		return it->second;
	}
}

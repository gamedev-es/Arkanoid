#include "SceneManager.h"

namespace GDES {
SceneManager::~SceneManager() {
    for(auto& s : sceneMap) {
        Scene* scene = s.second;
        delete scene;
        scene = nullptr;
    }
    sceneMap.clear();
}

bool SceneManager::AddScene(int sceneIndex, Scene* scene, bool isCurrentScene) {
    if(!scene) {
        return false;
    }

    sceneMap.insert(std::make_pair(sceneIndex, scene));

    if(isCurrentScene) {
        currentScene = scene;
    }

    return true;
}

bool SceneManager::LoadScene(int sceneIndex) {
    std::map<int, Scene*>::iterator it = sceneMap.find(sceneIndex);

    if(it == sceneMap.end()) {
        return false; // No existe esa escena
    }

    currentScene = it->second;

    return true;
}

bool SceneManager::RemoveScene(int sceneIndex, bool removeFromMemory) {
    std::map<int, Scene*>::iterator it = sceneMap.find(sceneIndex);

    if(it == sceneMap.end()) {
        return false; // No existe esa escena
    }

    // Lo dejamos opcional en caso que no se quiera borrar la scene
    // solo quitarlo del listado
    if(removeFromMemory) {
        Scene* scene = it->second;
        delete scene;
        scene = NULL;
    }

    sceneMap.erase(it);

    return true;
}

Scene* SceneManager::GetScene(int sceneIndex) {
    std::map<int, Scene*>::iterator it = sceneMap.find(sceneIndex);

    if(it == sceneMap.end()) {
        return NULL; // No existe esa escena
    }

    return it->second;
}
}

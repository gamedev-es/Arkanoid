#include "Scene.h"

namespace GDES {
Scene::~Scene() {
    std::vector<Entity*>::const_iterator it;
    for(it = entityList.begin(); it != entityList.end(); ++it) {
        Entity* entity = (*it);
        delete entity;
        entity = NULL;
    }
    entityList.clear();
}

void Scene::AddEntity(Entity* entity) {
    entity->LoadContent();
    entityList.push_back(entity);
}

void Scene::Update(sf::Time elapsedTime) {
    std::vector<Entity*>::const_iterator it;
    for(it = entityList.begin(); it != entityList.end(); ++it) {
        (*it)->Update(elapsedTime);
    }
}

void Scene::Draw(sf::RenderWindow* window) {

    if(!window) {
        return; // Nada que dibujar
    }

    std::vector<Entity*>::const_iterator it;
    for(it = entityList.begin(); it != entityList.end(); ++it) {
        (*it)->Draw(window);
    }
}
}

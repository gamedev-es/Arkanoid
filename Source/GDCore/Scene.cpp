#include "Scene.h"

namespace GDES {
Scene::~Scene() {
    for(auto& e : entityList) {
        Entity* entity = e;
        delete entity;
        entity = nullptr;
    }

    entityList.clear();
}

void Scene::AddEntity(Entity* entity) {
    entity->LoadContent();
    entityList.push_back(entity);
}

void Scene::Update(sf::Time elapsedTime) {
    for(auto& e : entityList) e->Update(elapsedTime);
}

void Scene::Draw(sf::RenderWindow* window) {

    if(!window) {
        return; // Nada que dibujar
    }

    for(auto& e : entityList) e->Draw(window);
}
} // namespace GDES

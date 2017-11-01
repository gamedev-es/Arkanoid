#include "Scene.h"

namespace GDES {

	void Scene::Initialize() {
		for (auto& e : entityList) {
			e->Initialize();
		}
	}

	void Scene::AddEntity(std::shared_ptr<IEntity>&& entity) {
		entityList.emplace_back(std::move(entity));
	}

	void Scene::Update(sf::Time elapsedTime) {
		for (auto& e : entityList) {
			e->Update(elapsedTime);
		}
	}

	void Scene::Draw(const std::unique_ptr<sf::RenderWindow> & window) {
		if (!window) {
			return; // Nada que dibujar
		}

		for (auto& e : entityList) {
			e->Draw(window);
		}
	}
} // namespace GDES

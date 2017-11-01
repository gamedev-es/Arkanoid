#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "IEntity.h"

namespace GDES {
	class Scene {
	public:
		Scene() :name("") {}
		Scene(std::string sceneName) : name(sceneName) {}
		virtual ~Scene() = default;

		virtual std::string GetName() { return name; }
		virtual void Initialize();
		virtual void Update(sf::Time elapsedTime);
		virtual void Draw(const std::unique_ptr<sf::RenderWindow> & window);
		virtual void AddEntity(std::shared_ptr<IEntity>&& entity);
	protected:
		std::string name;
		std::vector<std::shared_ptr<IEntity>> entityList;
	};
}

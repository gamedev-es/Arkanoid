#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Entity.h"

namespace GDES
{
	class Scene
	{
	public:
		Scene() =default;
		virtual ~Scene();

		virtual void Update(sf::Time elapsedTime);
		virtual void Draw(sf::RenderWindow* window);
		virtual void AddEntity(Entity* entity);
	private:
		std::vector<Entity*> entityList;
	};
}

#endif // SCENE_H

#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace GDES
{
	class Entity
	{
	public:
		Entity();
		~Entity();

		virtual void LoadContent() = 0;
		virtual void Update(sf::Time elapsedTime) = 0;
		virtual void Draw(sf::RenderWindow* window) = 0;
	};
}


#endif // ENTITY_H

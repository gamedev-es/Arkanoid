#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>

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

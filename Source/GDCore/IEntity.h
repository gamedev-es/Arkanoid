#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

namespace GDES {
	class IEntity {
	public:
		IEntity() = default;
		virtual ~IEntity() = default;

		virtual void Initialize() = 0;
		virtual void Update(sf::Time elapsedTime) = 0;
		virtual void Draw(const std::unique_ptr<sf::RenderWindow> & window) = 0;
	};
}

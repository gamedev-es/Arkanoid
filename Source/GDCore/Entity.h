#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

namespace GDES {
class Entity {
  public:
    Entity() = default;
    virtual ~Entity() = default;

    virtual void LoadContent() = 0;
    virtual void Update(sf::Time elapsedTime) = 0;
    virtual void Draw(sf::RenderWindow* window) = 0;
};
}

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "Entity.h"

namespace GDES {
class Scene {
  public:
    Scene() = default;
    virtual ~Scene();

    virtual void Update(sf::Time elapsedTime);
    virtual void Draw(sf::RenderWindow* window);
    virtual void AddEntity(Entity* entity);

  private:
    std::vector<Entity*> entityList;
};
}

#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "Entity.h"

namespace GDES {
class Scene {
  public:
    virtual ~Scene() = default;

    virtual void Update(sf::Time elapsedTime);
    virtual void Draw(sf::RenderWindow* window);
    virtual void AddEntity(std::shared_ptr<Entity>&& entity);

  private:
    std::vector<std::shared_ptr<Entity>> entityList;
};
}

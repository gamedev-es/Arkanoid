#ifndef BRICK_H
#define BRICK_H

#include "../GDCore/Entity.h"
#include "Arkanoid.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class Brick : public GDES::Entity {
  public:
    Brick(int x, int y, sf::Color color = sf::Color::Blue);
    ~Brick();
    virtual void LoadContent() override;
    virtual void Update(sf::Time elapsedTime) override;
    virtual void Draw(sf::RenderWindow* window) override;

  public:
    int GetWidth();
    int GetHeight();

  private:
    int width = 60;
    int height = 20;

    sf::RectangleShape rectangle;
    sf::Vector2f position;
};

#endif // BRICK_H

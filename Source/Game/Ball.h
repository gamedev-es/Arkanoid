#pragma once

#include "../GDCore/Entity.h"
#include "Arkanoid.h"
#include <SFML/Graphics.hpp>

class Ball : public GDES::Entity {
  public:
    Ball();

    virtual void LoadContent() override;
    virtual void Update(sf::Time elapsedTime) override;
    virtual void Draw(sf::RenderWindow* window) override;

  public:
    void Throw(sf::Vector2f direction, float acceleration);
    void Capture(sf::Vector2f pos);
    bool IsCaught() const;
    float GetRadius() const;

  private:
    bool IsCollideX() const;
    bool IsCollideY() const;

    void LoseBall();
    void SetPos(float x, float y);

  private:
    sf::CircleShape ball;
    sf::Vector2f direction{1, 1};
    float acceleration = 5;
    float speed = 600;
    bool caught{false};
};

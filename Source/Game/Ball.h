#pragma once

#include "../GDCore/Entity.h"
#include "Arkanoid.h"
#include <SFML/Graphics.hpp>
#include "CollisionObserver.h"

using CollisionObserverPtr = std::shared_ptr<CollisionObserver>;
class Ball : public GDES::Entity {
  public:
    Ball();

    virtual void LoadContent() override;
    virtual void Update(sf::Time elapsedTime) override;
    virtual void Draw(sf::RenderWindow* window) override;

  public:
    void updatePaddlePos(const sf::Vector2u new_pos);
    void updatePaddleSize(const sf::Vector2u new_pos);
    void Throw(sf::Vector2f direction, float acceleration);
    void Capture(sf::Vector2f pos);
    bool IsCaught() const;
    float GetRadius() const;
    sf::Vector2f GetPosition() const;
    void notifyObserver();
    void addObserver(CollisionObserverPtr observer);
    void reverseDirection();

  private:
    bool IsCollideX() const;
    bool IsCollideY() const;
    bool isPaddleCollide() const;
    void LoseBall();
    void SetPos(float x, float y);
    
  private:
    sf::CircleShape ball;
    sf::Vector2f direction{1, 1};
    float acceleration = 5;
    float speed = 600;
    bool caught{false};

    sf::Vector2u paddle_position{SCREEN_WIDTH, SCREEN_HEIGHT};
    sf::Vector2u paddle_size{0, 0};

    std::vector<CollisionObserverPtr> observers;
};

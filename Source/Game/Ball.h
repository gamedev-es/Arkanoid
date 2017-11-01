#pragma once

#include "../GDCore/IEntity.h"
#include "Arkanoid.h"
#include <SFML/Graphics.hpp>
#include "CollisionObserver.h"

using CollisionObserverPtr = std::shared_ptr<CollisionObserver>;
class Ball 
	: public std::enable_shared_from_this<Ball>, 
	  public GDES::IEntity
{
public:
	Ball();

	virtual void Initialize();
	virtual void Update(sf::Time elapsedTime);
	virtual void Draw(const std::unique_ptr<sf::RenderWindow> & window);

public:
	void UpdatePaddlePos(const sf::Vector2u new_pos);
	void UpdatePaddleSize(const sf::Vector2u new_pos);
	void Throw(sf::Vector2f direction, float acceleration);
	void Capture(sf::Vector2f pos);
	bool IsCaught() const;
	float GetRadius() const;
	sf::Vector2f GetPosition() const;
	void NotifyObserver();
	void AddObserver(CollisionObserverPtr observer);
	void ReverseDirection();

private:
	bool IsCollideX() const;
	bool IsCollideY() const;
	bool IsPaddleCollide() const;
	void LoseBall();
	void SetPos(float x, float y);

private:
	sf::CircleShape ball;
	sf::Vector2f direction{ 1, 1 };
	float acceleration = 5;
	float speed = 600;
	bool caught{ false };

	sf::Vector2u paddle_position{ SCREEN_WIDTH, SCREEN_HEIGHT };
	sf::Vector2u paddle_size{ 0, 0 };

	std::vector<CollisionObserverPtr> observers;
};

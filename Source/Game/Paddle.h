#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include <SFML\Graphics.hpp>
#include "../GDCore/Entity.h"
#include "Ball.h"

class Paddle : public GDES::Entity
{
public:
    Paddle(Ball *ball);
	~Paddle();

	virtual void LoadContent() override;
	virtual void Update(sf::Time elapsedTime) override;
	virtual void Draw(sf::RenderWindow* window) override;
private:
    Ball* ball;

    int width = 120;
    int height = 20;
    sf::RectangleShape rectangle;
    sf::Vector2f position;
    float speed = 5.0f;
    float padding = 20;
    int dir = 1;
    float limitLeft = padding;
    float limitRight = ((Arkanoid::SCREEN_WIDTH - rectangle.getSize().x) - padding);

};

#endif // PADDLE_H


#pragma once
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "../GDCore/Entity.h"
#include "Arkanoid.h"

using namespace sf;

class Ball : public GDES::Entity
{
public:
        Ball();

        virtual void LoadContent() override;
        virtual void Update(sf::Time elapsedTime) override;
        virtual void Draw(sf::RenderWindow* window) override;

public:
    void Throw(sf::Vector2f direction, float acceleration);
    void Capture(sf::Vector2f pos);
    bool IsCaught();
    float GetRadius();

private:
    bool IsCollideX();
    bool IsCollideY();


    void LoseBall();
    void SetPos(int x, int y);

private:
    sf::CircleShape ball;
    sf::Vector2f direction;
    float   acceleration = 5;
    float   speed = 600;
    bool    caught;
};

#endif // BALL_H

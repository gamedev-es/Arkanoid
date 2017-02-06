#pragma once
#ifndef PADDLE_H
#define PADDLE_H


#include "../GDCore/Entity.h"
#include <math.h>
#include <SFML\Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "Paddle.h"
#include "Arkanoid.h"
#include "ButtonState.h"
#include "Ball.h"

class Paddle : public GDES::Entity{

    public:
        Paddle(Ball* ball);
	~Paddle();

	virtual void LoadContent() override;
	virtual void Update(sf::Time elapsedTime) override;
	virtual void Draw(sf::RenderWindow* window) override;

    private:
        const float Tau = 0.3f;
        float limitSpeed = 500;
        float speed = 100;
        float limitLeft = 20;
        float moveTime;
        float limitRight;
        float initialSpeed;
        int width = 120;
        int height = 20;
        Ball* ball;
        sf::RectangleShape rectangle;
        sf::Vector2f position;

        //objetos para controlar la duración de las pulsaciones
        ButtonState *sLeft;
        ButtonState *sRight;

        void Speed(float speedlimit,float Tau);


};

#endif // PADDLE_H




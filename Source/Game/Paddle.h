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
        //movimiento
        const float Tau = 0.3f;
        const float limitSpeed = 500;
        float speed;
        float moveTime;
        float initialSpeed;

        //limites en pantalla
        const float limitLeft = 20;
        float limitRight;

        //tamaño raqueta
        int width = 120;
        int height = 20;


        sf::RectangleShape rectangle;
        sf::Vector2f position;

        //objetos para controlar la duración de las pulsaciones
        ButtonState *sLeft;
        ButtonState *sRight;

        //cosas raras
        Ball* ball;
        std::default_random_engine generator;

        //metodos privados
        void Speed(float speedlimit,float Tau);


};

#endif // PADDLE_H




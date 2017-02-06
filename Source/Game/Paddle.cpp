#include "Paddle.h"
#include "Arkanoid.h"



Paddle::Paddle(Ball *ball)
{
    this->ball = ball;
    this->rectangle.setSize(sf::Vector2f(width, height));
    this->position = sf::Vector2f(100, (Arkanoid::SCREEN_HEIGHT - (rectangle.getSize().y * 2)));
}

Paddle::~Paddle()
{

}

void Paddle::LoadContent()
{
	rectangle.setPosition(position);
}

void Paddle::Update(sf::Time elapsedTime)
{

	if (position.x < limitLeft) {
		dir = 1;
		position.x = limitLeft;
	}

	if (position.x > limitRight) {
		dir = -1;
		position.x = limitRight;
	}

    // Movimiento a la izquierda
	if (Arkanoid::GetInputManager()->IsKeyDown(sf::Keyboard::Left)) {
		position.x += speed * -1;
		rectangle.setPosition(position);
	}

    // Movimiento a la derecha
	if (Arkanoid::GetInputManager()->IsKeyDown(sf::Keyboard::Right)) {
		position.x += speed;
		rectangle.setPosition(position);
	}

    // Capturamos la bola
    if (Arkanoid::GetInputManager()->IsKeyDown(sf::Keyboard::Space)) {
        this->ball->Capture(sf::Vector2f(position.x + ((width - this->ball->GetRadius()) / 2), position.y - 50));
    }
    else
    {
        if (this->ball->IsCaught())
            this->ball->Throw(sf::Vector2f(-1,-1), 0);
    }


	/*
	//Movimiento automatizado
	position.x += speed * dir;
	rectangle.setPosition(position);
	*/

}

void Paddle::Draw(sf::RenderWindow* window)
{
	window->draw(rectangle);
}

#include "Paddle.h"
#include "Arkanoid.h"
#include <SFML\Graphics.hpp>

sf::RectangleShape rectangle(sf::Vector2f(120, 30));
sf::Vector2f position(100, (Arkanoid::SCREEN_HEIGHT - (rectangle.getSize().y * 2)));
float speed = 5.0f;
float padding = 20;
int dir = 1;
float limitLeft = padding;
float limitRight = ((Arkanoid::SCREEN_WIDTH - rectangle.getSize().x) - padding);

Paddle::Paddle()
{

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

	if (Arkanoid::GetInputManager()->IsKeyDown(sf::Keyboard::Left)) {
		position.x += speed * -1;
		rectangle.setPosition(position);
	}

	if (Arkanoid::GetInputManager()->IsKeyDown(sf::Keyboard::Right)) {
		position.x += speed;
		rectangle.setPosition(position);
	}

	/*
	//Movimiento automatizado
	position.x += speed * dir;
	rectangle.setPosition(position);
	*/

}

void Paddle::Draw(sf::RenderWindow* window)
{
	if (!window)
	{
		return; //Nada que dibujar
	}

	window->draw(rectangle);
}

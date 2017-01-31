#include "Paddle.h"
#include <SFML\Graphics.hpp>

sf::RectangleShape rectangle(sf::Vector2f(120, 30));
sf::Vector2f position(100, 540);
float speed = 5.0f;
float padding = 20;
int dir = 1;

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
	float limitLeft = padding;
	float limitRight = ( (800 - rectangle.getSize().x) - padding);

	if (position.x < limitLeft) {
		dir = 1;
		position.x = limitLeft;
	}
	
	if (position.x > limitRight) {
		dir = -1;
		position.x = limitRight;
	}

	position.x += speed * dir;
	rectangle.setPosition(position);

}

void Paddle::Draw(sf::RenderWindow* window)
{
	if (!window)
	{
		return; //Nada que dibujar
	}

	window->draw(rectangle);
}

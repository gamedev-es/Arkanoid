#include "Ball.h"
#include <math.h>

Ball::Ball()
{
	ball.setRadius(10.f);
	ball.setPosition(20, 20);
	ball.setFillColor(sf::Color::Cyan);
	caught = false;
	direction.x = 1;
	direction.y = 1;
}

void Ball::LoadContent()
{

}

void Ball::Update(sf::Time elapsedTime)
{
	// Capturada
	if (!caught)
	{
		ball.move(direction * speed * elapsedTime.asSeconds());

		if (IsCollideX())
			direction.x *= -1;

		if (IsCollideY())
			direction.y *= -1;
	}
}


void Ball::Draw(sf::RenderWindow* window)
{
	window->draw(ball);
}

void Ball::Capture(sf::Vector2f pos)
{
	caught = true;
	SetPos((int)pos.x, (int)pos.y);
}

void Ball::Throw(const sf::Vector2f direction, const float acceleration)
{
	//direccion normalizada
	this->direction.x = direction.x / sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	this->direction.y = direction.y / sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	caught = false;
}

void Ball::SetPos(int x, int y)
{
	ball.setPosition(sf::Vector2f((float)x, (float)y));
}

bool Ball::IsCollideX()
{
	if (ball.getPosition().x + 2 * ball.getRadius() >= (Arkanoid::SCREEN_WIDTH) || ball.getPosition().x <= 0)
	{
		return true;
	}
	return false;
}

bool Ball::IsCollideY()
{
	if (ball.getPosition().y + 2 * ball.getRadius() >= (Arkanoid::SCREEN_HEIGHT) || ball.getPosition().y <= 0)
	{
		return true;
	}
	return false;
}

bool Ball::IsCaught()
{
	return caught;
}

float Ball::GetRadius()
{
	return ball.getRadius();
}

void Ball::LoseBall()
{
	// Aquí si la bola se pierde en la parte inferior
}

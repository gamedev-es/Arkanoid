#include "Ball.h"



Ball::Ball()
{
	ball.setRadius(10.f);
	ball.setPosition(20, 20);
	ball.setFillColor(Color::Cyan);
    this->caught = false;
    this->direction.x = 1;
    this->direction.y = 1;
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

        if (CollideX())
            direction.x *= -1;

        if (CollideY())
            direction.y *= -1;
    }
}


void Ball::Draw(sf::RenderWindow* window)
{
	window->draw(ball);
}

void Ball::Throw(sf::Vector2f* direction, float acceleration)
{
    //this->direction = direction;

}

void Ball::SetPos(int x, int y)
{
    this->ball.setPosition(sf::Vector2f(x, y));
}

bool Ball::CollideX()
{
    if (ball.getPosition().x + 2 * ball.getRadius() >= (Arkanoid::SCREEN_WIDTH) || ball.getPosition().x <= 0)
    {
        return true;
    }
    return false;
}

bool Ball::CollideY()
{
    if (ball.getPosition().y + 2 * ball.getRadius() >= (Arkanoid::SCREEN_HEIGHT) || ball.getPosition().y <= 0)
    {
        return true;
    }
    return false;
}

void Ball::LoseBall()
{
    // Aquí si la bola se pierde en la parte inferior
}



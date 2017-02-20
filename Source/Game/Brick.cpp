#include "Brick.h"

Brick::Brick(int x, int y, sf::Color color)
{
    rectangle.setFillColor(color);
    this->rectangle.setSize(sf::Vector2f(width,height));
    rectangle.setPosition(sf::Vector2f(x, y));
}

void Brick::LoadContent()
{

}

void Brick::Update(sf::Time elapsedTime)
{

}

void Brick::Draw(sf::RenderWindow* window)
{
    window->draw(this->rectangle);
}

int Brick::GetWidth()
{
    return this->width;
}

int Brick::GetHeight()
{
    return this->height;
}

Brick::~Brick()
{

}



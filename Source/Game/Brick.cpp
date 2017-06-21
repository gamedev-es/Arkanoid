#include "Brick.h"

Brick::Brick(unsigned x, unsigned y, sf::Color color) {
    rectangle.setFillColor(color);
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setPosition(sf::Vector2f(x, y));
}

void Brick::LoadContent() {
}

void Brick::Update(sf::Time elapsedTime) {
}

void Brick::Draw(sf::RenderWindow* window) {
    window->draw(rectangle);
}

unsigned Brick::GetWidth() {
    return width;
}

unsigned Brick::GetHeight() {
    return height;
}

Brick::~Brick() {
}

#include <cmath>

#include "Brick.h"
#include "Ball.h"

Brick::Brick(unsigned x, unsigned y, unsigned char strength, sf::Color color) : visible(true) {
    rectangle.setFillColor(color);
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setPosition(sf::Vector2f(x, y));
	this->brickStrength = strength;
}

void Brick::LoadContent() {
}

void Brick::Update(sf::Time elapsedTime) {
    if(visible)
    {
        
    }
}

void Brick::Draw(sf::RenderWindow* window) {
    if (visible) {
        window->draw(rectangle);
    }
}

bool Brick::CircleSphereCollision(const Ball* ball) {
    if (!visible) {
        return false;
    }

    const auto radius = ball->GetRadius();
    const auto pos = ball->GetPosition();
    const auto position = rectangle.getPosition();
    auto collided = false;
    
    const sf::Vector2f halfSize(width / 2, height / 2);

    const auto dist_x = std::abs(pos.x - position.x - width / 2);
    const auto dist_y = std::abs(pos.y - position.y - height / 2);

    //Hay que pulir esta parte que la he hecho rapido sin pensar mucho que tengo que ir a comprar xDD
    if (dist_x <= (width / 2 + radius) && (dist_y <= height / 2 + radius)) {
        if (dist_x <= width / 2) collided = collided || true;
        if (dist_y <= height / 2) collided = collided || true;

        const auto dx = dist_x - width / 2;
        const auto dy = dist_y - height / 2;

        collided = collided || (dx*dx + dy*dy <= radius*radius);
        if (collided) {
			this->brickStrength--;
			if(this->brickStrength <= 0)
				visible = false;
        }
    }
    return collided;
}


unsigned Brick::GetWidth() {
    return width;
}

unsigned Brick::GetHeight() {
    return height;
}

float Brick::euclideanDistance(const sf::Vector2f& pos1,
    const sf::Vector2f& pos2) const {
    auto resX = (pos1.x - pos2.x)*(pos1.x - pos2.x);
    auto resY = (pos1.y - pos2.y)*(pos2.y - pos2.y);
    return resX + resY;
}




Brick::~Brick() {
}

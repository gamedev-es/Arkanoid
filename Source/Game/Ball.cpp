#include "Ball.h"
#include <math.h>

Ball::Ball() {
    ball.setRadius(10.f);
    ball.setPosition(20, 20);
    ball.setFillColor(sf::Color::Cyan);
}

void Ball::LoadContent() {
}

void Ball::Update(sf::Time elapsedTime) {
    // Capturada
    if(!caught) {
        ball.move(direction * speed * elapsedTime.asSeconds());

        if(IsCollideX()) direction.x *= -1;

        if(IsCollideY()) direction.y *= -1;
    }
}

void Ball::Draw(sf::RenderWindow* window) {
    window->draw(ball);
}

void Ball::Capture(sf::Vector2f pos) {
    caught = true;
    SetPos(pos.x, pos.y);
}

void Ball::Throw(const sf::Vector2f old_dir, const float acceleration) {
    // direccion normalizada
    direction.x = old_dir.x / sqrt(pow(old_dir.x, 2) + pow(old_dir.y, 2));
    direction.y = old_dir.y / sqrt(pow(old_dir.x, 2) + pow(old_dir.y, 2));
    caught = false;
}

void Ball::SetPos(float x, float y) {
    ball.setPosition(sf::Vector2f(x, y));
}

bool Ball::IsCollideX() const {
    if(ball.getPosition().x + 2 * ball.getRadius() >= (Arkanoid::SCREEN_WIDTH) ||
       ball.getPosition().x <= 0) {
        return true;
    }
    return false;
}

bool Ball::IsCollideY() const {
    if(ball.getPosition().y + 2 * ball.getRadius() >= (Arkanoid::SCREEN_HEIGHT) ||
       ball.getPosition().y <= 0) {
        return true;
    }
    return false;
}

bool Ball::IsCaught() const {
    return caught;
}

float Ball::GetRadius() const {
    return ball.getRadius();
}

void Ball::LoseBall() {
    // Aquí si la bola se pierde en la parte inferior
}

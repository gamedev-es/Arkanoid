#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <math.h>
#include <memory>
#include <random>

#include "../GDCore/Entity.h"
#include "Arkanoid.h"
#include "Ball.h"
#include "ButtonState.h"
#include "Paddle.h"

class Paddle : public GDES::Entity {

  public:
    explicit Paddle();

    void LoadContent() override;
    void Update(sf::Time elapsedTime) override;
    void Draw(sf::RenderWindow* window) override;
    void AddBall(std::shared_ptr<Ball> ball);
  private:
    // movimiento
    const float TAU = 0.3f;
    const float LIMIT_SPEED = 500;
    float speed{0};
    float moveTime{0};
    float initialSpeed{0};

    // limites en pantalla
    float limitLeft = 20;
    float limitRight = 0;

    // tamaño raqueta
    unsigned width = 120;
    unsigned height = 20;

    sf::RectangleShape rectangle;
    sf::Vector2f position;

    // objetos para controlar la duración de las pulsaciones
    std::unique_ptr<ButtonState> sLeft{new ButtonState()};
    std::unique_ptr<ButtonState> sRight{new ButtonState()};

    // cosas raras
    std::vector<std::shared_ptr<Ball>> balls;
    std::default_random_engine generator;

    // metodos privados
    void Speed(float speedlimit, float tau);
};

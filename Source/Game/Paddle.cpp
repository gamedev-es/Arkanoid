#include "Paddle.h"

Paddle::Paddle() {
    rectangle.setSize(sf::Vector2f(width, height));
    position = sf::Vector2f(100, SCREEN_HEIGHT - (rectangle.getSize().y * 2));
    limitRight = (SCREEN_WIDTH - rectangle.getSize().x) - 20;
}

void Paddle::LoadContent() {
    rectangle.setPosition(position);
}

void Paddle::Update(sf::Time elapsedTime) {

    if(position.x < limitLeft) {
        position.x = limitLeft;
    } else if(position.x > limitRight) {
        position.x = limitRight;
    }

    /* =================================================================================================
     * CONTROLES DE LA PALA
     *================================================================================================*/

    // pulsar izquierda
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sLeft->buttonDown = true;
        sRight->buttonDown = false; // No quiero que esten activados a la vez

        if(sLeft->stateChange) { // Necesario para calcular la velocidad
                                 // objetivo
            initialSpeed = speed;
        }

        moveTime = sLeft->steadyTime;
        Speed(-LIMIT_SPEED, TAU);
    }

    // pulsar derecha
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sRight->buttonDown = true;
        sLeft->buttonDown = false; // No quiero que esten activados a la vez

        if(sRight->stateChange) { // Necesario para calcular la velocidad
                                  // objetivo
            initialSpeed = speed;
        }

        moveTime = sRight->steadyTime;
        Speed(LIMIT_SPEED, TAU);
    }
    // frenada (nada pulsado)
    else {
        sRight->buttonDown = false;
        sLeft->buttonDown = false;

        // es un pequeño lio para determinar que steady Time hay que usar
        if(sLeft->stateChange || sRight->stateChange) {
            initialSpeed = speed;
        }
        if(sRight->steadyTime < sLeft->steadyTime)
            moveTime = sRight->steadyTime;
        else
            moveTime = sLeft->steadyTime;

        Speed(0, TAU);
    }

    // Posicion a partir de velocidad
    position.x += speed * elapsedTime.asSeconds();
    rectangle.setPosition(position);

    sRight->timeUpdate(elapsedTime);
    sLeft->timeUpdate(elapsedTime);

    /*CAPTURAR LA BOLA===========================================
    *Fragmento de codigo correspondiente al saque de la bola
    *Cuando se encuentra pegada a la paleta
    *================================================*/

    if (balls.size() > 0) {
        Ball * ball = balls[0];
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            ball->Capture(sf::Vector2f(position.x + (width / 2 - ball->GetRadius()),
                position.y - 50));
        }
        else {
            if (ball->IsCaught()) {

                // lanzamiento aleatorio de la bola
                std::normal_distribution<float> distribution(0.0f, 0.3f);

                auto direction = sf::Vector2f(
                    distribution(generator) + speed * elapsedTime.asSeconds() / 7, -1);
                ball->Throw(direction, 0);
            }
        }

        for (auto& curr : balls) {
            curr->updatePaddlePos(sf::Vector2u(position.x, position.y));
            curr->updatePaddleSize(sf::Vector2u(width, height));
        }
    }
}

void Paddle::Draw(sf::RenderWindow* window) {
    window->draw(rectangle);
}

void Paddle::AddBall(Ball* ball) {
    balls.push_back(ball);
}

/* aceleración de la paleta
 -> limite de velocidad
 -> rapidez de transitorio
 */
void Paddle::Speed(float speedlimit, float tau) {
    speed = speedlimit + (initialSpeed - speedlimit) * exp(-tau * moveTime);
}

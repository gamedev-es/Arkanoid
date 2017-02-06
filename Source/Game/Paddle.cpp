#include <math.h>
#include "Paddle.h"
#include "Arkanoid.h"
#include <SFML\Graphics.hpp>
#include <SFML/System/Time.hpp>


Paddle::Paddle(){
    this->rectangle.setSize(sf::Vector2f(100,20));
    this->position = sf::Vector2f(100, (Arkanoid::SCREEN_HEIGHT - (rectangle.getSize().y * 2)));

    limitRight = ((Arkanoid::SCREEN_WIDTH - rectangle.getSize().x) - 20);

    //objetos para controlar la duración de las pulsaciones
    sLeft = new ButtonState();
    sRight = new ButtonState();

}

Paddle::~Paddle(){

}

void Paddle::LoadContent(){
        rectangle.setPosition(this->position);
}

void Paddle::Update(sf::Time elapsedTime){


	if (position.x < limitLeft) {
		position.x = limitLeft;
	}

        else if (position.x > limitRight) {
		position.x = limitRight;
	}

        //pulsar izquierda
	if (Arkanoid::GetInputManager()->IsKeyDown(sf::Keyboard::Left)) {
                this->sLeft->buttonDown = true;
                this->sRight->buttonDown = false; //No quiero que esten activados a la vez

                if (sLeft->stateChange){    //Necesario para calcular la velocidad objetivo
                    this->initialSpeed = this->speed;
                }

                this->moveTime = sLeft->steadyTime;
                Speed(-this->limitSpeed,Tau);
	}
        //pulsar derecha
        else if (Arkanoid::GetInputManager()->IsKeyDown(sf::Keyboard::Right)) {
                sRight->buttonDown = true;
                sLeft->buttonDown = false; //No quiero que esten activados a la vez

                if (sRight->stateChange){    //Necesario para calcular la velocidad objetivo
                    this->initialSpeed = this->speed;
                }

                this->moveTime = sRight->steadyTime;
                Speed(this->limitSpeed,Tau);
	}
        //frenada
        else{
            sRight->buttonDown = false;
            sLeft->buttonDown = false;

            //es un pequeño lio para determinar que steady Time hay que usar
            if (sLeft->stateChange || sRight->stateChange){
                this->initialSpeed = this->speed;
            }
            if (sRight->steadyTime<sLeft->steadyTime)
                this->moveTime = sRight->steadyTime;
            else
                this->moveTime = sLeft->steadyTime;

            this->Speed(0,Tau);
        }

        //Posicion a partir de velocidad
        position.x += this->speed*elapsedTime.asSeconds();
        rectangle.setPosition(position);

        sRight->timeUpdate(elapsedTime);
        sLeft->timeUpdate(elapsedTime);

}

void Paddle::Draw(sf::RenderWindow* window){
        window->draw(this->rectangle);
}


/* aceleración de la paleta
 -> limite de velocidad
 -> rapidez de transitorio
 */
void Paddle::Speed(float speedlimit,float Tau){
    this->speed = speedlimit +(initialSpeed-speedlimit)*exp(-Tau*this->moveTime);

}





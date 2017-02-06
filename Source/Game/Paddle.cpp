#include <math.h>
#include "Paddle.h"
#include "Arkanoid.h"
#include <SFML\Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "Ball.h"


Paddle::Paddle(Ball *ball){
    this->ball = ball;
    this->rectangle.setSize(sf::Vector2f(width,height));
    this->position = sf::Vector2f(100, (Arkanoid::SCREEN_HEIGHT - (rectangle.getSize().y * 2)));

    limitRight = ((Arkanoid::SCREEN_WIDTH - rectangle.getSize().x) - 20);

    //objetos para controlar la duración de las pulsaciones
    sLeft = new ButtonState();
    sRight = new ButtonState();

}

Paddle::~Paddle(){
    delete sLeft;
    delete sRight;
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

        /* =================================================================================================
         * CONTROLES DE LA PALA
         *================================================================================================*/

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
        //frenada (nada pulsado)
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

        /*CAPTURAR LA BOLA===========================================
        *Fragmento de codigo correspondiente al saque de la bola
        *Cuando se encuentra pegada a la paleta
        *by @scyper ================================================*/

        if (Arkanoid::GetInputManager()->IsKeyDown(sf::Keyboard::Space)) {
           this->ball->Capture(sf::Vector2f(position.x + ((width - this->ball->GetRadius()) / 2), position.y - 50));
        }
        else
        {
           if (this->ball->IsCaught())
               this->ball->Throw(sf::Vector2f(-1,-1), 0);
        }

        /*=================================================================
         * FIN controles
         * ==============================================================*/





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





#include "Paddle.h"

Paddle::Paddle(Ball *ball) {
	this->ball = ball;

	rectangle.setSize(sf::Vector2f((float)width, (float)height));
	position = sf::Vector2f(100, (Arkanoid::SCREEN_HEIGHT - (rectangle.getSize().y * 2)));
	limitRight = ((Arkanoid::SCREEN_WIDTH - rectangle.getSize().x) - 20);

	//objetos para controlar la duración de las pulsaciones
	sLeft = new ButtonState();
	sRight = new ButtonState();
}

Paddle::~Paddle() {
	delete sLeft;
	delete sRight;
}

void Paddle::LoadContent() {
	rectangle.setPosition(position);
}

void Paddle::Update(sf::Time elapsedTime) {

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sLeft->buttonDown = true;
		sRight->buttonDown = false; //No quiero que esten activados a la vez

		if (sLeft->stateChange) {    //Necesario para calcular la velocidad objetivo
			initialSpeed = speed;
		}

		moveTime = sLeft->steadyTime;
		Speed(-LIMIT_SPEED, TAU);
	}

	//pulsar derecha
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sRight->buttonDown = true;
		sLeft->buttonDown = false; //No quiero que esten activados a la vez

		if (sRight->stateChange) {    //Necesario para calcular la velocidad objetivo
			initialSpeed = speed;
		}

		moveTime = sRight->steadyTime;
		Speed(LIMIT_SPEED, TAU);
	}
	//frenada (nada pulsado)
	else {
		sRight->buttonDown = false;
		sLeft->buttonDown = false;

		//es un pequeño lio para determinar que steady Time hay que usar
		if (sLeft->stateChange || sRight->stateChange) {
			initialSpeed = speed;
		}
		if (sRight->steadyTime < sLeft->steadyTime)
			moveTime = sRight->steadyTime;
		else
			moveTime = sLeft->steadyTime;

		Speed(0, TAU);
	}

	//Posicion a partir de velocidad
	position.x += speed * elapsedTime.asSeconds();
	rectangle.setPosition(position);

	sRight->timeUpdate(elapsedTime);
	sLeft->timeUpdate(elapsedTime);

	/*CAPTURAR LA BOLA===========================================
	*Fragmento de codigo correspondiente al saque de la bola
	*Cuando se encuentra pegada a la paleta
	*================================================*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ball->Capture(sf::Vector2f(position.x + ((width / 2 - ball->GetRadius())), position.y - 50));
	}
	else
	{
		if (ball->IsCaught()) {

			//lanzamiento aleatorio de la bola
			std::normal_distribution<float> distribution(0.0f, 0.3f);

			ball->Throw(sf::Vector2f(distribution(generator) + speed*elapsedTime.asSeconds() / 7, -1), 0);
		}
	}

	/*=================================================================
	 * FIN controles
	 * ==============================================================*/
}

void Paddle::Draw(sf::RenderWindow* window) {
	window->draw(rectangle);
}

/* aceleración de la paleta
 -> limite de velocidad
 -> rapidez de transitorio
 */
void Paddle::Speed(float speedlimit, float tau) {
	speed = speedlimit + (initialSpeed - speedlimit) * exp(-tau * moveTime);
}





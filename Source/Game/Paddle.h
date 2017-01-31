#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include "../GDCore/Entity.h"

class Paddle : public GDES::Entity
{
public:
	Paddle();
	~Paddle();

	virtual void LoadContent() override;
	virtual void Update(sf::Time elapsedTime) override;
	virtual void Draw(sf::RenderWindow* window) override;
};

#endif // PADDLE_H


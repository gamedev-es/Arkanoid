#pragma once
#ifndef BALL_H
#define BALL_H

#include "../GDCore/Entity.h"

class Ball : public GDES::Entity
{
public:
	Ball();

	virtual void LoadContent() override;
	virtual void Update(sf::Time elapsedTime) override;
	virtual void Draw(sf::RenderWindow* window) override;
};

#endif // BALL_H

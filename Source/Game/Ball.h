#pragma once
#ifndef BALL_H
#define BALL_H

#include "../GDCore/Entity.h"

using namespace GDES;

class Ball : public Entity
{
public:
    Ball();

    void LoadContent();
    void Update(sf::Time elapsedTime);
    void Draw();
};

#endif // BALL_H

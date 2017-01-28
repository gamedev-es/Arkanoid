#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include "../GDCore/Entity.h"

using namespace GDES;

class Paddle : public Entity
{
public:
    Paddle();

    void LoadContent();
    void Update(sf::Time elapsedTime);
    void Draw();
};

#endif // PADDLE_H


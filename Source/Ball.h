#ifndef BALL_H
#define BALL_H

#include "GDEngine/Entity.h"

using namespace GDE;

class Ball : public Entity
{
public:
    Ball();

    void LoadContent();
    void Update(sf::Time elapsedTime);
    void Draw();
};

#endif // BALL_H

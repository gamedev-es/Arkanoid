#ifndef PADDLE_H
#define PADDLE_H

#include "GDEngine/Entity.h"

using namespace GDE;

class Paddle : public Entity
{
public:
    Paddle();

    void LoadContent();
    void Update(sf::Time elapsedTime);
    void Draw();
};

#endif // PADDLE_H


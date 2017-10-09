#include "CollisionObserver.h"
#include <iostream>
#include "Ball.h"
#include "Brick.h"

CollisionObserver::CollisionObserver()
{
}


CollisionObserver::~CollisionObserver()
{
}

void CollisionObserver::update(Ball* ball) {

    bool hasCollision = false;
    std::shared_ptr<Brick> collidedBrick = nullptr;
    for(auto it = bricks.begin(); it != bricks.end() && !hasCollision; ++it)
    {
        if((*it)->CircleSphereCollision(ball))
        {
            hasCollision = true;
            collidedBrick = *it;
        }
    }
    if(hasCollision)
    {
        ball->reverseDirection();
        //Recitificar collided brick

        //Notification to some observers: Manage Score, Bonification or something else. 
        //notifyObservers(collidedBrick) 
    }
}

void CollisionObserver::addCollidableBrick(std::shared_ptr<Brick> brick) {
    bricks.push_back(brick);
}


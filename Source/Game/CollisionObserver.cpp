#include "CollisionObserver.h"
#include <iostream>
#include "Ball.h"
#include "Brick.h"

void CollisionObserver::Update(std::shared_ptr<Ball> ball) {

	bool hasCollision = false;
	std::shared_ptr<Brick> collidedBrick = nullptr;
	for (auto it = bricks.begin(); it != bricks.end() && !hasCollision; ++it)
	{
		if ((*it)->CircleSphereCollision(ball))
		{
			hasCollision = true;
			collidedBrick = *it;
		}
	}
	if (hasCollision)
	{
		ball->ReverseDirection();
		//Recitificar collided brick

		//Notification to some observers: Manage Score, Bonification or something else. 
		//notifyObservers(collidedBrick) 
	}
}

void CollisionObserver::AddCollidableBrick(std::shared_ptr<Brick> brick) {
	bricks.push_back(brick);
}


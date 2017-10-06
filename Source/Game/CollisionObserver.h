#pragma once
#include <memory>
#include <vector>

class Ball;
class Brick;

class CollisionObserver
{
public:
    CollisionObserver();
    ~CollisionObserver();
    void update(Ball * ball);
    void addCollidableBrick(std::shared_ptr<Brick> brick);
private:
    std::vector<std::shared_ptr<Brick>> bricks;


};


#pragma once
#include <memory>
#include <vector>

class Ball;
class Brick;

class CollisionObserver
{
public:
	CollisionObserver() = default;
	~CollisionObserver() = delete;
	void Update(std::shared_ptr<Ball> ball);
	void AddCollidableBrick(std::shared_ptr<Brick> brick);
private:
	std::vector<std::shared_ptr<Brick>> bricks;
};


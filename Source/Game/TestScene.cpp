#include <memory>

#include "TestScene.h"
#include "BrickFactory.h"


void TestScene::Initialize() {
	Scene::Initialize();

	//brickCollision = std::make_shared<CollisionObserver>();

	CreateBricks();

	auto ball = std::make_shared<Ball>();
	auto paddle = std::make_unique<Paddle>();
	paddle->AddBall(ball);
	//ball->AddObserver(brickCollision);

	auto ball2 = std::make_shared<Ball>();
	//ball2->AddObserver(brickCollision);

	auto ball3 = std::make_shared<Ball>();
	//ball3->AddObserver(brickCollision);

	AddEntity(std::move(paddle));
	AddEntity(std::move(ball));
	AddEntity(std::move(ball2));
	AddEntity(std::move(ball3));

}

void TestScene::CreateBricks() {
	unsigned xPos = 20;
	unsigned yPos = 50;

	BrickFactory factory;

	//PATTERN: R->Red, Y->Yellow, B->Blue , G->Green, anything else empty slot 
	const char* pattern[5] = { "RYRYRYRYRYRY", "RYRYRYRYRYRY" , "BBBBBBBBBBBB" , "RYR------YRY" , "RYG------GYR" };

	for (int v = 0; v < 5; v++) {
		for (int h = 0; h < 12; h++) {
			auto value = pattern[v][h];

			if (factory.HasBrick(value)) {
				auto brick = factory.CreateBrick(value, xPos, yPos);
				//brickCollision->AddCollidableBrick(brick);
				AddEntity(std::move(brick));
			}

			xPos += 60 + 1; //const?? 

		}
		xPos = 20;
		yPos += 20 + 1;
	}
}


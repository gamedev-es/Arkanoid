#include "TestScene.h"
#include "Paddle.h"
#include "Ball.h"

void TestScene::Initialize()
{
	Paddle* paddle = new Paddle();
	Ball* ball = new Ball();
	AddEntity(paddle);
	AddEntity(ball);
}
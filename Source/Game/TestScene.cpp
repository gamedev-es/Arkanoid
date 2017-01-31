#include "TestScene.h"
#include "Paddle.h"

void TestScene::Initialize()
{
	Paddle* paddle = new Paddle();
	AddEntity(paddle);
}
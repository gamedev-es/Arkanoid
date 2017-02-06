#include "TestScene.h"
#include "Paddle.h"
#include "Ball.h"
#include "ButtonState.h"

void TestScene::Initialize()
{
	Paddle* paddle = new Paddle();
	Ball* ball = new Ball();
        AddEntity(paddle);
	AddEntity(ball);
}

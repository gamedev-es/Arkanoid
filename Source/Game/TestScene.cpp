#include "TestScene.h"
#include "Paddle.h"
#include "Ball.h"
#include "ButtonState.h"

void TestScene::Initialize()
{

        Ball* ball = new Ball();
        Paddle* paddle = new Paddle(ball);
	AddEntity(paddle);
        AddEntity(ball);
}

#include "TestScene.h"


void TestScene::Initialize()
{
    CreateBricks();

    Ball* ball = new Ball();
    Paddle* paddle = new Paddle(ball);

    AddEntity(paddle);
    AddEntity(ball);
}


void TestScene::CreateBricks()
{
    int xPos = 20;
    int yPos = 50;

    for (int v = 0; v < 5; v++)
    {
        for (int h = 0; h < 12; h++)
        {
            Brick* brick = new Brick(xPos, yPos, ((h % 2) == 0)? Color::Yellow : Color::Red);

            brickList.push_back(brick);
            AddEntity(brick);

            xPos += brick->GetWidth() + 1;
        }
        xPos = 20;
        yPos += 20 + 1;
    }
}

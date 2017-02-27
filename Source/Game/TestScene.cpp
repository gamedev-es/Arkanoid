#include "TestScene.h"

TestScene::TestScene() : Scene()
{
	Initialize();
}

TestScene::~TestScene()
{

}

void TestScene::Initialize()
{
	CreateBricks();
        Light* light = new Light(sf::Vector2f(250,250),120.0f,sf::Color::Blue);
	Ball* ball = new Ball();
	Paddle* paddle = new Paddle(ball);


	AddEntity(paddle);
	AddEntity(ball);
        AddEntity(light);
}


void TestScene::CreateBricks()
{
	int xPos = 20;
	int yPos = 50;

	for (int v = 0; v < 5; v++)
	{
		for (int h = 0; h < 12; h++)
		{
			Brick* brick = new Brick(xPos, yPos, ((h % 2) == 0) ? sf::Color::Yellow : sf::Color::Red);

			brickList.push_back(brick);
			AddEntity(brick);

			xPos += brick->GetWidth() + 1;
		}
		xPos = 20;
		yPos += 20 + 1;
	}
}

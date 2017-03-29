#include "TestScene.h"

TestScene::TestScene() : Scene()
{
	Initialize();
}

TestScene::~TestScene()
{
	if (bgTexture) {
		delete bgTexture;
		bgTexture = nullptr;
	}
}

void TestScene::Initialize()
{

	bgTexture = new sf::Texture();
	bgTexture->loadFromFile("Assets/Textures/floortiled.png");
	bgSprite.setTexture((*bgTexture));
	bgSprite.setPosition(0, 0);

	CreateBricks();

	Light* light = new Light();

	light->newLight(sf::Vector2f(400, 100), 0.4f, sf::Vector3f(1, 0, 0), 0, 0);
	light->newLight(sf::Vector2f(400, 300), 0.4f, sf::Vector3f(0, 1, 0), 0, 0);
	light->newLight(sf::Vector2f(400, 500), 1.0f, sf::Vector3f(0, 0, 1), 0, 0);

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


void TestScene::Draw(sf::RenderWindow* window) {
	window->draw(bgSprite);
	Scene::Draw(window);
}
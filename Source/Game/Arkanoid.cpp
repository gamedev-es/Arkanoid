#include "Arkanoid.h"
#include "TestScene.h"

Arkanoid::Arkanoid() :
	GDCore("Arkanoid", SCREEN_WIDTH, SCREEN_HEIGHT)
{
	GetSceneManager()->AddScene(std::make_shared<TestScene>(), true);
}

#include "Arkanoid.h"
#include "TestScene.h"

Arkanoid::Arkanoid()
    :GDCore("Arkanoid", 800, 600)
{
	TestScene* testScene = new TestScene();
	sceneManager.AddScene(SCENES_LIST::TEST, testScene, true);
}

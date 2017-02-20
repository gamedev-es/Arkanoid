#include "Arkanoid.h"
#include "TestScene.h"

Arkanoid::Arkanoid()
    :GDCore("Arkanoid", Arkanoid::SCREEN_WIDTH, Arkanoid::SCREEN_HEIGHT)
{
    GetSceneManager()->AddScene(1, new TestScene(), true);
}

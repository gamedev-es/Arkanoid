#include "Arkanoid.h"
#include "TestScene.h"

Arkanoid::Arkanoid() : GDCore("Arkanoid", SCREEN_WIDTH, SCREEN_HEIGHT) {
    GetSceneManager()->AddScene(SCENES::TEST, new TestScene(), true);
}

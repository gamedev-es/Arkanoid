#include "TestScene.h"

TestScene::TestScene() : Scene() {
    Initialize();
}

TestScene::~TestScene() {
}

void TestScene::Initialize() {
    CreateBricks();

    Ball* ball = new Ball();
    Paddle* paddle = new Paddle(ball);

    AddEntity(paddle);
    AddEntity(ball);
}

void TestScene::CreateBricks() {
    unsigned xPos = 20;
    unsigned yPos = 50;

    for(int v = 0; v < 5; v++) {
        for(int h = 0; h < 12; h++) {
            auto color = (h % 2) ? sf::Color::Red : sf::Color::Yellow;
            Brick* brick = new Brick(xPos, yPos, color);

            brickList.emplace_back(brick);
            AddEntity(brick);

            xPos += brick->GetWidth() + 1;
        }
        xPos = 20;
        yPos += 20 + 1;
    }
}

#include <memory>

#include "TestScene.h"

TestScene::TestScene() {
    Initialize();
}

void TestScene::Initialize() {
    CreateBricks();

    auto* ball = new Ball();
    auto paddle = std::make_unique<Paddle>(ball);

    AddEntity(std::move(paddle));
    AddEntity(std::unique_ptr<Ball>(ball));
}

void TestScene::CreateBricks() {
    unsigned xPos = 20;
    unsigned yPos = 50;

    for(int v = 0; v < 5; v++) {
        for(int h = 0; h < 12; h++) {
            auto color = (h % 2) ? sf::Color::Red : sf::Color::Yellow;
            auto brick = std::make_unique<Brick>(xPos, yPos, color);
            xPos += brick->GetWidth() + 1;

            AddEntity(std::move(brick));
        }
        xPos = 20;
        yPos += 20 + 1;
    }
}

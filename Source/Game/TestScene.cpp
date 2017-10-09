#include <memory>

#include "TestScene.h"

TestScene::TestScene() {
    Initialize();
}

void TestScene::Initialize() {
    brickCollision = std::make_shared<CollisionObserver>();

    CreateBricks();

    auto ball = std::make_shared<Ball>();
    auto paddle = std::make_unique<Paddle>();
    paddle->AddBall(ball);
    ball->addObserver(brickCollision);

    auto ball2 = std::make_shared<Ball>();
    ball2->addObserver(brickCollision);

    auto ball3 = std::make_shared<Ball>();
    ball3->addObserver(brickCollision);

    AddEntity(std::move(paddle));
    AddEntity(std::move(ball));
    AddEntity(std::move(ball2));
    AddEntity(std::move(ball3));


}

void TestScene::CreateBricks() {
    unsigned xPos = 20;
    unsigned yPos = 50;

    for(int v = 0; v < 5; v++) {
        for(int h = 0; h < 12; h++) {
            auto color = (h % 2) ? sf::Color::Red : sf::Color::Yellow;
            auto brick = std::make_shared<Brick>(xPos, yPos, color);
            xPos += brick->GetWidth() + 1;

            brickCollision->addCollidableBrick(brick);
            AddEntity(brick);
        }
        xPos = 20;
        yPos += 20 + 1;
    }
}


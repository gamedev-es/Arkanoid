#include <memory>

#include "TestScene.h"

TestScene::TestScene() {
    Initialize();
}

void TestScene::Initialize() {
    brickCollision = std::make_shared<CollisionObserver>();

    CreateBricks();

    auto* ball = new Ball();
    auto paddle = std::make_unique<Paddle>();
    paddle->AddBall(ball);
    ball->addObserver(brickCollision);

    auto ball2 = new Ball();
    ball2->addObserver(brickCollision);

    auto ball3 = new Ball();
    ball3->addObserver(brickCollision);

    AddEntity(std::move(paddle));
    AddEntity(std::unique_ptr<Ball>(ball));
    AddEntity(std::unique_ptr<Ball>(ball2));
    AddEntity(std::unique_ptr<Ball>(ball3));


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
            AddBreakable(brick);
        }
        xPos = 20;
        yPos += 20 + 1;
    }
}

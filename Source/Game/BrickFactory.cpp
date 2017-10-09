#include "BrickFactory.h"
#include <SFML/Window/Keyboard.hpp>
#include "Brick.h"

BrickFactory::BrickFactory() {
    Init();
}

void BrickFactory::Init() {
    templates['G'] = sf::Color::Green;
    templates['Y'] = sf::Color::Yellow;
    templates['R'] = sf::Color::Red;
    templates['B'] = sf::Color::Blue;
}

bool BrickFactory::HasBrick(char id) {
    return templates.find(id) != templates.end();
}

std::shared_ptr<Brick> BrickFactory::CreateBrick(char pattern, int x,
    int y) {

   auto color = templates[pattern];
   return std::make_shared<Brick>(x, y, color);
}

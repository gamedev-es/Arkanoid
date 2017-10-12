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

	//Number of hits asociated to each color
	strength['G'] = 1;
	strength['Y'] = 2;
	strength['R'] = 3;
	strength['B'] = 5;
}

bool BrickFactory::HasBrick(char id) {
    return templates.find(id) != templates.end();
}

std::shared_ptr<Brick> BrickFactory::CreateBrick(char pattern, int x,
    int y) {

   auto color = templates[pattern];
   unsigned char brickStrength = strength[pattern];
   return std::make_shared<Brick>(x, y, brickStrength, color);
}

#pragma once

#include <unordered_map>
#include <SFML/Graphics/Color.hpp>
#include <memory>

class Brick;

class BrickFactory
{
public:
    BrickFactory();
    void Init();
    bool HasBrick(char id);
    std::shared_ptr<Brick> CreateBrick(char pattern, int x, int y);
    virtual ~BrickFactory() = default;
private:
    //only color template, different brick definition. [Map: -Memory eff, +Flexibility] 
    std::unordered_map<char, sf::Color> templates;
};

#include "../GDCore/Entity.h"
#include "Arkanoid.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class Brick : public GDES::Entity {
  public:
    Brick(unsigned x, unsigned y, sf::Color color = sf::Color::Blue);
    ~Brick();
    virtual void LoadContent() override;
    virtual void Update(sf::Time elapsedTime) override;
    virtual void Draw(sf::RenderWindow* window) override;

  public:
    unsigned GetWidth();
    unsigned GetHeight();

  private:
    unsigned width = 60;
    unsigned height = 20;

    sf::RectangleShape rectangle;
    sf::Vector2f position;
};

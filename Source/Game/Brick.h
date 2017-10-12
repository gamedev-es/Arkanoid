#include "../GDCore/Entity.h"
#include "Arkanoid.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class Ball;

class Brick : public GDES::Entity {
  public:
    Brick(unsigned x, unsigned y,unsigned char strength, sf::Color color = sf::Color::Blue);
    ~Brick();
    virtual void LoadContent() override;
    virtual void Update(sf::Time elapsedTime) override;
    virtual void Draw(sf::RenderWindow* window) override;
    virtual bool CircleSphereCollision(const Ball * ball);
  public:
    unsigned GetWidth();
    unsigned GetHeight();

  private:
    float euclideanDistance(const sf::Vector2f & pos1, const sf::Vector2f &  pos2) const ;
    unsigned width = 60;
    unsigned height = 20;
	unsigned char brickStrength; 
    bool visible; 
    sf::RectangleShape rectangle;
    sf::Vector2f position;
};

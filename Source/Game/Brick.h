#include "../GDCore/IEntity.h"
#include "Arkanoid.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class Ball;

class Brick : public GDES::IEntity {
public:
	Brick(unsigned x, unsigned y, unsigned char strength, sf::Color color = sf::Color::Blue);
	~Brick();
	virtual void Initialize();
	virtual void Update(sf::Time elapsedTime);
	virtual void Draw(const std::unique_ptr<sf::RenderWindow> & window);
	virtual bool CircleSphereCollision(std::shared_ptr<Ball> ball);
public:
	unsigned GetWidth();
	unsigned GetHeight();

private:
	float EuclideanDistance(const sf::Vector2f & pos1, const sf::Vector2f &  pos2) const;
	unsigned width = 60;
	unsigned height = 20;
	char brickStrength;
	bool visible;
	sf::RectangleShape rectangle;
	sf::Vector2f position;
};

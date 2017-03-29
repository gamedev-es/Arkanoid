#include "light.h"
#include <SFML/Graphics.hpp>
#include <iterator>


void Light::newLight(sf::Vector2f position, float bright, sf::Vector3f color)
{
	lightSource AuxLight;
	AuxLight.position = position;
	AuxLight.bright = bright;
	AuxLight.color = color;
	AuxLight.angle = 0;
	AuxLight.angularAtenuation = 0;

	lightSourcesList.push_back(AuxLight);
}

void Light::newLight(sf::Vector2f position, float bright, sf::Vector3f color, float angle, float angularAt)
{
	lightSource AuxLight;
	AuxLight.position = position;
	AuxLight.bright = bright;
	AuxLight.color = color;
	AuxLight.angle = angle;
	AuxLight.angularAtenuation = angularAt;

	lightSourcesList.push_back(AuxLight);
}


void Light::Draw(sf::RenderWindow* window)
{
	//window->draw(blackLayout);
	//window->draw(vertices, 4, sf::Quads, &simpleShader);
	window->draw(spriteShader, sf::BlendMultiply);
	//window->draw(spriteShader);
}


void Light::Update(sf::Time elapsedTime)
{
	//itera la lista de luces y genera la capa de iluminacion (mejorable, ya que redibuja las cosas que dibujo en el foto
	//grama anterior
	lightTexture.clear(sf::Color::Black);
	int count = 0;
	for (std::list<lightSource>::iterator lightIterator = lightSourcesList.begin(); lightIterator !=
		lightSourcesList.end(); ++lightIterator)
	{

		simpleShader.setUniform("position", lightIterator->position);
		simpleShader.setUniform("color", lightIterator->color);
		simpleShader.setUniform("bright", lightIterator->bright);
		simpleShader.setUniform("intensity", lightIterator->intensity);
		simpleShader.setUniform("ScreenWidth", (float)Arkanoid::SCREEN_WIDTH);
		simpleShader.setUniform("ScreenHeight", (float)Arkanoid::SCREEN_HEIGHT);
		simpleShader.setUniform("radius", lightIterator->radius);
		simpleShader.setUniform("angle", lightIterator->angle);
		simpleShader.setUniform("angularAtenuation", lightIterator->angularAtenuation);
		simpleShader.setUniform("texture", &lightTexture);

		//lightTexture.draw(blackLayout, &simpleShader);
		lightTexture.draw(vertices, 4, sf::Quads, &simpleShader);
		//Para usar esto, pon un breakpoint, dale continue hasta que count = 0 nuevamente
		//lightTexture.getTexture().copyToImage().saveToFile("lightTexture_"+std::to_string(count)+".png");
		count++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		lightTexture.getTexture().copyToImage().saveToFile("lightTexture.png");
	}

	lightTexture.display();
	spriteShader.setTexture(lightTexture.getTexture());
}

void Light::LoadContent()
{
	lightTexture.create(Arkanoid::SCREEN_WIDTH, Arkanoid::SCREEN_HEIGHT);
	lightTexture.setSmooth(true);
	blackLayout.setPosition(sf::Vector2f(0, 0));
	blackLayout.setFillColor(sf::Color::Black);
	blackLayout.setSize(sf::Vector2f(Arkanoid::SCREEN_WIDTH, Arkanoid::SCREEN_HEIGHT));

	//simpleShader.loadFromFile("Assets/Shaders/GatoShader.frag", sf::Shader::Fragment);
	//simpleShader.loadFromFile("Assets/Shaders/PointLightA.vert", "Shaders/PointLightA.frag");
	simpleShader.loadFromFile("Assets/Shaders/PointLightB.frag", sf::Shader::Fragment);

	struct Rect {
		int x;
		int y;
		int width;
		int height;
	};

	Rect quad;

	quad.x = 0;
	quad.y = 0;
	quad.width = quad.x + Arkanoid::SCREEN_WIDTH;
	quad.height = quad.y + Arkanoid::SCREEN_HEIGHT;

	vertices[0] = sf::Vertex(sf::Vector2f(quad.x, quad.y), sf::Vector2f(0, 0));
	vertices[1] = sf::Vertex(sf::Vector2f(quad.width, quad.y), sf::Vector2f(1, 0));
	vertices[2] = sf::Vertex(sf::Vector2f(quad.width, quad.height), sf::Vector2f(1, 1));
	vertices[3] = sf::Vertex(sf::Vector2f(quad.x, quad.height), sf::Vector2f(0, 1));

}

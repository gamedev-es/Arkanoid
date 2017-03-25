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
        window->draw(blackLayout);
}


void Light::Update(sf::Time elapsedTime)
{
    //itera la lista de luces y genera la capa de iluminacion (mejorable, ya que redibuja las cosas que dibujo en el foto
    //grama anterior
    lightTexture.clear(sf::Color::Black);

    for(std::list<lightSource>::iterator lightIterator = lightSourcesList.begin() ; lightIterator !=
        lightSourcesList.end() ; ++lightIterator)
    {
        simpleShader.setUniform("position",lightIterator->position);
        simpleShader.setUniform("color",lightIterator->color);
        simpleShader.setUniform("bright",lightIterator->bright);
        simpleShader.setUniform("angle",lightIterator->angle);
        simpleShader.setUniform("angularAtenuation",lightIterator->angularAtenuation);
        simpleShader.setUniform("texture",&lightTexture);

        lightTexture.draw(blackLayout,&simpleShader);   //posiblemente el problema esté aquí
    }
    lightTexture.display();
    blackLayout.setTexture(&lightTexture.getTexture());
}

void Light::LoadContent()
{
    lightTexture.create(Arkanoid::SCREEN_WIDTH,Arkanoid::SCREEN_HEIGHT);
    blackLayout.setPosition(sf::Vector2f(0,0));
    blackLayout.setFillColor(sf::Color::Black);
    blackLayout.setSize(sf::Vector2f(Arkanoid::SCREEN_WIDTH,Arkanoid::SCREEN_HEIGHT));
}

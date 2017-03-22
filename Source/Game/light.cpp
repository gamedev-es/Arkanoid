#include "light.h"
#include <SFML/Graphics.hpp>




Light::Light(sf::Vector2f position, float bright,sf::Vector3f color)
{
    basicLight.position = position;
    basicLight.bright = bright;
    basicLight.color = color;
    basicLight.direction = sf::Vector2f(0,0);
    basicLight.lateralAtenuation = NULL;

    simpleShader.loadFromMemory(shaderText,sf::Shader::Fragment);
}


Light::Light(sf::Vector2f position, float bright,sf::Vector3f color,sf::Vector2f direction, float lateralAt)
{
    basicLight.position = position;
    basicLight.bright = bright;
    basicLight.color = color;
    basicLight.direction = direction;
    basicLight.lateralAtenuation = lateralAt;


    simpleShader.loadFromMemory(shaderText,sf::Shader::Fragment);
}



void Light::Draw(sf::RenderWindow* window)
{
        window->draw(blackLayout,&simpleShader);
}


void Light::Update(sf::Time elapsedTime)
{
    basicLight.direction += sf::Vector2f(0.1,0);
    simpleShader.setUniform("position",basicLight.position);
    simpleShader.setUniform("color",basicLight.color);
    simpleShader.setUniform("bright",basicLight.bright);
    simpleShader.setUniform("direction",basicLight.direction);
    simpleShader.setUniform("lateralAtenuation",basicLight.lateralAtenuation);
    //simpleShader.setUniform("texture",lightTexture);
}

void Light::LoadContent()
{
    blackLayout.setPosition(sf::Vector2f(0,0));
    blackLayout.setFillColor(sf::Color::Black);
    blackLayout.setSize(sf::Vector2f(Arkanoid::SCREEN_WIDTH,Arkanoid::SCREEN_HEIGHT));
}

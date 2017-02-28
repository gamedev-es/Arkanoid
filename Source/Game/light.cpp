#include "light.h"
#include <SFML/Graphics.hpp>




Light::Light(sf::Vector2f position, float bright,sf::Vector3f color)
{
    basicLight.position = position;
    basicLight.bright = bright;
    basicLight.color = color;

    shaderText = \
            "uniform vec2 position;" \
            "uniform vec3 color;" \
            "uniform float bright;" \
            "void main()" \
            "{" \
                    "float dist = distance(gl_FragCoord.xy,position);" \
                    "if(true)" \
                    "{" \
                        "gl_FragColor = vec4(0.0,0.0,0.0,1.0);" \
                        "gl_FragColor.xyz = (color*exp(-dist/50.0))+((1.0,1.0,1.0)*bright*exp(-dist/20.0)); " \
                    "}" \
            "}";

    simpleShader.loadFromMemory(shaderText,sf::Shader::Fragment);
    simpleShader.setUniform("position",basicLight.position);
    simpleShader.setUniform("color",basicLight.color);
    simpleShader.setUniform("bright",basicLight.bright);
}


void Light::Draw(sf::RenderWindow* window)
{
        window->draw(blackLayout,&simpleShader);
}


void Light::Update(sf::Time elapsedTime)
{

}

void Light::LoadContent()
{
    blackLayout.setPosition(sf::Vector2f(0,0));
    blackLayout.setFillColor(sf::Color::Black);
    blackLayout.setSize(sf::Vector2f(Arkanoid::SCREEN_WIDTH,Arkanoid::SCREEN_HEIGHT));
}

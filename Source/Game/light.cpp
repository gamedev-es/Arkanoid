#include "light.h"




Light::Light(sf::Vector2f position, float intensity,sf::Color color)
{
    basicLight.position = position;
    basicLight.intensity = intensity;
    basicLight.color = color;

    shaderText = \
            "uniform vec2 position;" \
            "void main()" \
            "{" \
                    "float dist = distance(gl_FragCoord.xy,position);" \
                    "if(true)" \
                    "{" \
                        "gl_FragColor = vec4(0.0,0.0,0.0,1.0);" \
                        "gl_FragColor.a = 0.5 + 0.5*sin(dist/300);" \
                        "gl_FragColor.g = exp(-dist/100.0);" \
                    "}" \
            "}";

    simpleShader.loadFromMemory(shaderText,sf::Shader::Fragment);
    simpleShader.setUniform("position",basicLight.position);
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

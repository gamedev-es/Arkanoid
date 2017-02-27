#ifndef LIGHT_H
#define LIGHT_H

#include <SFML/Graphics.hpp>
#include "../GDCore/Entity.h"
#include "Arkanoid.h"




struct directional{
    sf::Vector2f direction;
    float lateralAtenuation;
};

struct basics{
    sf::Vector2f position;
    float intensity;
    sf::Color color;
};


class Light: public GDES::Entity
    {
    public:

        //Constructor basico para luz omnidireccional
        Light(sf::Vector2f position, float intensity, sf::Color color);

        virtual void LoadContent() override;
        virtual void Update(sf::Time elapsedTime) override;
        virtual void Draw(sf::RenderWindow* window) override;

    private:
        basics basicLight;

        //dado que no es imprescindible, sera un puntero vacío salvo que haga falta
        directional* coneLight;

        sf::Shader simpleShader;
        std::string shaderText;

        sf::RectangleShape blackLayout;


    };

#endif // LIGHT_H

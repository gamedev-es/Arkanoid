#ifndef LIGHT_H
#define LIGHT_H

#include <SFML/Graphics.hpp>
#include "../GDCore/Entity.h"
#include "Arkanoid.h"
#include <list>


class Light: public GDES::Entity
    {
    public:

        sf::RenderTexture lightTexture;

        //Metodos que añaden luces
        void newLight(sf::Vector2f position, float bright, sf::Vector3f color);
        void newLight(sf::Vector2f position, float bright, sf::Vector3f color, float angle, float angularAt);
		

        virtual void LoadContent() override;
        virtual void Update(sf::Time elapsedTime) override;
        virtual void Draw(sf::RenderWindow* window) override;

    private:
        //Estructura para almacenar la info de cada fuente de luz
        struct lightSource{
            sf::Vector2f position;
            float bright;
			float intensity = 1;
			float radius = 100;
            sf::Vector3f color;
            float angle;
            float angularAtenuation;
        };

        lightSource basicLight;
		sf::Vertex vertices[4];
        std::list<lightSource> lightSourcesList;
		sf::Sprite spriteShader;
        sf::Shader simpleShader;
        sf::RectangleShape blackLayout;

    };

#endif // LIGHT_H

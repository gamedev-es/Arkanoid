#ifndef LIGHT_H
#define LIGHT_H

#include <SFML/Graphics.hpp>
#include "../GDCore/Entity.h"
#include "Arkanoid.h"
#include <forward_list>


class Light: public GDES::Entity
    {
    public:

        sf::RenderTexture lightTexture;

        //Constructor basico para luz omnidireccional
        Light(sf::Vector2f, float, sf::Vector3f);
        //Constructor para luz direccional
        Light(sf::Vector2f position, float bright, sf::Vector3f color, sf::Vector2f direction, float lateralAt);


        virtual void LoadContent() override;
        virtual void Update(sf::Time elapsedTime) override;
        virtual void Draw(sf::RenderWindow* window) override;

    private:
        //Estructura para almacenar la info de cada fuente de luz
        struct lightSource{
            sf::Vector2f position;
            float bright;
            float intensity;
            sf::Vector3f color;
            sf::Vector2f direction;
            float lateralAtenuation;
        };


        lightSource basicLight;

        sf::Shader simpleShader;
        std::string shaderText = \
                "uniform vec2 position;" \
                "uniform vec3 color;" \
                "uniform float bright;" \
                "uniform vec2 direction;" \
                "uniform float lateralAtenuation;" \
                "void main()" \
                "{" \
                        "float dist = distance(gl_FragCoord.xy,position);" \
                        "float isThereDirection = distance(direction,vec2(0,0));" \
                        "gl_FragColor = vec4(0,0,0,1);" \
                        "if(isThereDirection <0.1)" \
                        "{" \
                            "gl_FragColor.xyz = (color*exp(-dist/50.0))+((1.0,1.0,1.0)*bright*exp(-dist/20.0)); " \
                        "}" \
                        "else" \
                        "{" \
                            "float dotProd = dot(gl_FragCoord.xy-position,direction);" \
                            "float modules = length(direction) * length(gl_FragCoord.xy-position);" \
                            "float cosAlpha = dotProd/modules;" \
                            "if(cosAlpha>lateralAtenuation)" \
                            "{" \
                                "gl_FragColor.xyz = (color*exp(-dist/250.0))+((1.0,1.0,1.0)*bright*exp(-dist/20.0));" \
                            "}" \
                        "}" \
                "}";

        sf::RectangleShape blackLayout;

        //forward_list<lightSource> lightList;






    };

#endif // LIGHT_H

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
            float intensity;
            sf::Vector3f color;
            float angle;
            float angularAtenuation;
        };


        lightSource basicLight;

        std::list<lightSource> lightSourcesList;
		sf::Sprite spriteShader;

        sf::Shader simpleShader;
		std::string vertShader = \
			"void main()"\
			"{"\
			"	gl_TexCoord[0] = gl_MultiTexCoord0;"\
			"	gl_Position = ftransform();"\
			"}";

        std::string fragShader = \
                "uniform sampler2D texture;" \
                "uniform vec2 position;" \
                "uniform vec3 color;" \
                "uniform float bright;" \
                "uniform float angle;" \
                "uniform float angularAtenuation;" \
                "void main()" \
                "{" \
                        "float dist = distance(gl_FragCoord.xy,position);" \
                        "gl_FragColor = texture2D(texture,gl_FragCoord.xy);" \
                        "if(angularAtenuation <0.001)" \
                        "{" \
                            "gl_FragColor.xyz += (color*exp(-dist/50.0))+((1.0,1.0,1.0)*bright*exp(-dist/20.0)); " \
                        "}" \
                        "else" \
                        "{" \
                            "float pixelAngle = atan((gl_FragCoord.xy-position).y,(gl_FragCoord.xy-position).x);" \
                            "if(abs(pixelAngle-radians(angle))<radians(angularAtenuation))" \
                            "{" \
                                "gl_FragColor.xyz += (color*exp(-dist/150.0)*exp(-abs(pixelAngle-radians(angle))))+((1.0,1.0,1.0)*bright*exp(-dist/20.0));" \
                            "}" \
                        "}" \
                "}";

        sf::RectangleShape blackLayout;

    };

#endif // LIGHT_H

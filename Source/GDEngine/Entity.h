#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>

namespace GDE
{
    class Entity
    {
    public:
        Entity();

        virtual void LoadContent() const = 0;
        virtual void Update(sf::Time elapsedTime) const = 0;
        virtual void Draw() const = 0;
    };
}


#endif // ENTITY_H

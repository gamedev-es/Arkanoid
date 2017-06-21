#ifndef BUTTONSTATE_H
#define BUTTONSTATE_H

#include <SFML/System/Time.hpp>
#include <iostream>
#include <string>

/*=================================================================================================================================================
 * clase que controla la duración de las pulsaciones de un boton arbitrario
 * recomiendo crear un objeto por boton y ese objeto contará el timepo que está
 * o no pulsado dicho boton */

class ButtonState {
  public:
    ButtonState();

    bool previousDown = false;
    void timeUpdate(sf::Time elapsedTime);

  public:
    bool buttonDown = false;
    float steadyTime = 0;
    bool stateChange = false;
};

#endif // BUTTONSTATE_H

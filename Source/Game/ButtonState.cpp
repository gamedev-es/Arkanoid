#include "ButtonState.h"

ButtonState::ButtonState() {
}

void ButtonState::timeUpdate(sf::Time elapsedTime) {
    steadyTime += elapsedTime.asSeconds(); // cuenta el tiempo transcurrido;
    if(buttonDown != previousDown) {
        steadyTime = 0;
        stateChange = true;
    }
    previousDown = buttonDown;
}

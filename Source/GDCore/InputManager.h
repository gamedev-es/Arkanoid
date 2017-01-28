#pragma once
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Window/Event.hpp>

namespace GDES
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void Initialize();
		void HandleEvent(sf::Event event);

		bool IsKeyDown(unsigned int);
	private:
		bool m_keys[256];
	};
};

#endif // INPUT_MANAGER_H
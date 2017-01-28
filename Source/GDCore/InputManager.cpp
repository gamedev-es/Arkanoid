#include "InputManager.h"

namespace GDES
{
	InputManager::InputManager()
	{
		Initialize();
	}


	void InputManager::Initialize()
	{
		for (int i = 0; i < 256; i++)
		{
			m_keys[i] = false;
		}
	}

	void InputManager::HandleEvent(sf::Event event)
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			m_keys[event.key.code] = true;
			break;

		case sf::Event::KeyReleased:
			m_keys[event.key.code] = false;
			break;
		}
	}
	bool InputManager::IsKeyDown(unsigned int key)
	{
		return m_keys[key];
	}

	InputManager::~InputManager()
	{

	}
};


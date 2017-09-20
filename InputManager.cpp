#include "DisplayManager.h"

#include "InputManager.h"

df::InputManager::InputManager()
{
}

df::InputManager & df::InputManager::getInstance()
{
	static InputManager inputManager;
	return inputManager;
}

int df::InputManager::startUp()
{
	if (!DM.isStarted())
	{
		return -1;
	}

	sf::RenderWindow *window = DM.getWindow();
	window->setKeyRepeatEnabled(false);

	Manager::startUp();
	return 0;
}

void df::InputManager::shutDown()
{
	if (DM.isStarted())
	{
		sf::RenderWindow *window = DM.getWindow();
		window->setKeyRepeatEnabled(true);
	}

	Manager::shutDown();
}

void df::InputManager::getInput()
{
}

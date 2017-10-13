#include "DisplayManager.h"
#include "LogManager.h"

#include "EventKeyboard.h"
#include "EventMouse.h"

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

	LM.writeLog("InputManager::startUp(): Starting up the Input Manager!");
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
	sf::Event event;
	while (DM.getWindow()->pollEvent(event))
	{
		// Key was pressed.
		if (event.type == sf::Event::KeyPressed)
		{
			EventKeyboard keyboard = EventKeyboard();
			keyboard.setKey(Keyboard::Key(event.key.code));
			keyboard.setKeyboardAction(KeyboardAction::KEY_PRESSED);
			onEvent(&keyboard);
		}

		// Key was released.
		if (event.type == sf::Event::KeyReleased)
		{
			EventKeyboard keyboard = EventKeyboard();
			keyboard.setKey(Keyboard::Key(event.key.code));
			keyboard.setKeyboardAction(KeyboardAction::KEY_RELEASED);
			onEvent(&keyboard);
		}

		// Mouse was moved.
		if (event.type == sf::Event::MouseMoved)
		{
			EventMouse mouse = EventMouse();
			mouse.setMouseAction(MouseAction::MOVED);
			mouse.setMousePosition(DM.pixelsToSpaces(Vector(event.mouseMove.x, event.mouseMove.y)));
			onEvent(&mouse);
		}

		// Mouse was clicked.
		if (event.type == sf::Event::MouseButtonPressed)
		{
			EventMouse mouse = EventMouse();
			mouse.setMouseButton(Mouse::Button(event.mouseButton.button));
			mouse.setMouseAction(MouseAction::CLICKED);
			mouse.setMousePosition(DM.pixelsToSpaces(Vector(event.mouseButton.x, event.mouseButton.y)));
			onEvent(&mouse);
		}
	}

	for (Keyboard::Key key : Keyboard::keys)
	{
		// Key is pressed.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(key)))
		{
			EventKeyboard keyboard = EventKeyboard();
			keyboard.setKey(key);
			keyboard.setKeyboardAction(KeyboardAction::KEY_DOWN);
			onEvent(&keyboard);
		}
	}


	for (Mouse::Button button : Mouse::buttons)
	{
		// Mouse button is pressed.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button(button)))
		{
			EventMouse mouse = EventMouse();
			mouse.setMouseButton(button);
			mouse.setMouseAction(MouseAction::PRESSED);
			onEvent(&mouse);
		}
	}
}

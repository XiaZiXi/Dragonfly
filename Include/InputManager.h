#pragma once

#include "Manager.h"

namespace df {
#define IM df::InputManager::getInstance()
	
class InputManager : public Manager {
private:
	InputManager();	// Private since a singleton.

public:
	InputManager(InputManager const&) = delete;		// Don't allow copy.
	void operator=(InputManager const&) = delete;	// Don't allow assignment.

	// Get the singleton instance of the WorldManager.
	static InputManager &getInstance();

	// Get window ready to capture input.
	// Return 0 if ok, else return -1.
	int startUp();

	// Revert back to normal window mode.
	void shutDown();

	// Get input from the keyboard and mouse.
	// Pass event along to all Objects.
	void getInput();
};
}
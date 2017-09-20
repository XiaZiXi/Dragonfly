#pragma once

#include "Key.h"
#include "KeyboardAction.h"
#include "Event.h"

namespace df {
const std::string KEYBOARD_EVENT = "df::keyboard";

class EventKeyboard : public Event {
private:
	Keyboard::Key m_keyVal;
	KeyboardAction m_keyboardAction;

public:
	// Default constructor.
	EventKeyboard();

	// Get/Set key in event.
	void setKey(Keyboard::Key newKey);
	Keyboard::Key getKey() const;

	// Get/Set keyboard event action.
	void setKeyboardAction(KeyboardAction newAction);
	KeyboardAction getKeyboardAction() const;
};
}
#include "EventKeyboard.h"

df::EventKeyboard::EventKeyboard()
{
	m_keyVal = Keyboard::Key::UNDEFINED_KEY;
	m_keyboardAction = UNDEFINED_KEYBOARD_ACTION;
}

void df::EventKeyboard::setKey(Keyboard::Key newKey)
{
	m_keyVal = newKey;
}

Keyboard::Key df::EventKeyboard::getKey() const
{
	return m_keyVal;
}

void df::EventKeyboard::setKeyboardAction(KeyboardAction newAction)
{
	m_keyboardAction = newAction;
}

df::KeyboardAction df::EventKeyboard::getKeyboardAction() const
{
	return m_keyboardAction;
}

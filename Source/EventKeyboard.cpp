#include "EventKeyboard.h"

df::EventKeyboard::EventKeyboard()
{
	setType(KEYBOARD_EVENT);
	m_keyVal = Keyboard::Key::UNDEFINED_KEY;
	m_keyboardAction = UNDEFINED_KEYBOARD_ACTION;
}

void df::EventKeyboard::setKey(Keyboard::Key newKey)
{
	m_keyVal = newKey;
}

df::Keyboard::Key df::EventKeyboard::getKey() const
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

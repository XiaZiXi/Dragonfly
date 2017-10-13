#include "EventMouse.h"

df::EventMouse::EventMouse()
{
	setType(MOUSE_EVENT);
	m_mouseAction = UNDEFINED_MOUSE_ACTION;
	m_mouseButton = Mouse::Button::UNDEFINED_MOUSE_BUTTON;
}

void df::EventMouse::setMouseAction(MouseAction newMouseAction)
{
	m_mouseAction = newMouseAction;
}

df::MouseAction df::EventMouse::getMouseAction() const
{
	return m_mouseAction;
}

void df::EventMouse::setMouseButton(Mouse::Button newButton)
{
	m_mouseButton = newButton;
}

df::Mouse::Button df::EventMouse::getMouseButton() const
{
	return m_mouseButton;
}

void df::EventMouse::setMousePosition(Vector newPos)
{
	m_mousePos = newPos;
}

df::Vector df::EventMouse::getMousePosition() const
{
	return m_mousePos;
}

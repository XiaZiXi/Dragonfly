#include "LogManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"

#include "EventOut.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "Vector.h"

#include "TestVelocityObject.h"

TestVelocityObject::TestVelocityObject()
{
	setType("TestVelocityObject");
	setVelocity(df::Vector(0.1, 0.1));
	setSolidness(df::Solidness::SOFT);
}

TestVelocityObject::~TestVelocityObject()
{
	LM.writeLog("TestVelocityObject::~TestVelocityObject(): Deleting TestVelocityObject at position: %f, %f", getPosition().getX(), getPosition().getY());
}

int TestVelocityObject::eventHandler(const df::Event *p_event)
{
	if (p_event->getType() == df::OUT_EVENT)
	{
		out();
		return 1;
	}
	if (p_event->getType() == df::KEYBOARD_EVENT)
	{
		auto keyboardEvent = dynamic_cast<const df::EventKeyboard *>(p_event);
		if (keyboardEvent)
		{
			if (keyboardEvent->getKey() == Keyboard::SPACE && keyboardEvent->getKeyboardAction() == df::KeyboardAction::KEY_PRESSED)
			{
				df::Vector currentVel = getVelocity();
				setVelocity(df::Vector(currentVel.getX(), currentVel.getY() * -1));
			}
		}
	}
	if (p_event->getType() == df::MOUSE_EVENT)
	{
		auto mouseEvent = dynamic_cast<const df::EventMouse *>(p_event);
		if (mouseEvent)
		{
			if (mouseEvent->getMouseButton() == Mouse::LEFT && mouseEvent->getMouseAction() == df::MouseAction::CLICKED)
			{
				df::Vector currentVel = getVelocity();
				setVelocity(df::Vector(currentVel.getX() * -1, currentVel.getY()));
			}
		}
	}
	return 0;
}

void TestVelocityObject::out()
{
	df::Vector currentVel = getVelocity();
	setVelocity(df::Vector(currentVel.getX() * -1, currentVel.getY() * -1));
	LM.writeLog("TestVelocityObject::out(): Velocities reversed to: %f, %f", currentVel.getX(), currentVel.getY());
}

void TestVelocityObject::draw()
{
	DM.drawString(getPosition(), "DEBUG_VELOCITY", df::Justification::CENTER_JUSTIFIED, df::Color::CYAN);
}

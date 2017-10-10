#include "LogManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"

#include "EventKeyboard.h"
#include "Vector.h"

#include "TestBoundaryObject.h"

TestBoundaryObject::TestBoundaryObject()
{
	setType("TestBoundaryObject");
	setPosition(df::Vector(0, 21));
}

TestBoundaryObject::~TestBoundaryObject()
{
	LM.writeLog("TestBoundaryObject::~TestBoundaryObject(): Deleting TestBoundaryObject at position: %f, %f", getPosition().getX(), getPosition().getY());
}

int TestBoundaryObject::eventHandler(const df::Event *p_event)
{
	if (p_event->getType() == df::KEYBOARD_EVENT)
	{
		auto keyboardEvent = dynamic_cast<const df::EventKeyboard *>(p_event);
		if (keyboardEvent)
		{
			if (keyboardEvent->getKey() == Keyboard::W && keyboardEvent->getKeyboardAction() == df::KeyboardAction::KEY_PRESSED)
			{
				WM.moveObject(this, df::Vector(getPosition().getX(), getPosition().getY() + 1));
			}
			if (keyboardEvent->getKey() == Keyboard::S && keyboardEvent->getKeyboardAction() == df::KeyboardAction::KEY_PRESSED)
			{
				WM.moveObject(this, df::Vector(getPosition().getX(), getPosition().getY() - 1));
			}
		}
		return 1;
	}
	return 0;
}

void TestBoundaryObject::draw()
{
	DM.drawString(getPosition(), "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890ABCDEFGHIJKLM", df::Justification::LEFT_JUSTIFIED, df::Color::MAGENTA);
}

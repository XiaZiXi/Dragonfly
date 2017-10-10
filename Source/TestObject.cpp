#include "LogManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"

#include "EventStep.h"
#include "EventOut.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "EventCollision.h"
#include "Vector.h"

#include "TestObject.h"

TestObject::TestObject(float startX, float startY)
{
	setType("TestObject");
	df::Vector pos(startX, startY);
	setPosition(pos);
	setVelocity(df::Vector(0, 1));
}

TestObject::~TestObject()
{
	LM.writeLog("TestObject::~TestObject(): Deleting TestObject at position: %f, %f", getPosition().getX(), getPosition().getY());
}

int TestObject::eventHandler(const df::Event *p_event)
{
	if (p_event->getType() == df::STEP_EVENT)
	{
		auto stepEvent = dynamic_cast<const df::EventStep *>(p_event);
		if (stepEvent)
		{
			if (stepEvent->getStepCount() % 20 == 0)
			{
				step();
			}
		}
		return 1;
	}
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
				WM.moveObject(this, df::Vector(getPosition().getX(), getPosition().getY() + 1));
			}
		}
		return 1;
	}
	if (p_event->getType() == df::MOUSE_EVENT)
	{
		auto mouseEvent = dynamic_cast<const df::EventMouse *>(p_event);
		if (mouseEvent)
		{
			if (mouseEvent->getMouseButton() == Mouse::LEFT && mouseEvent->getMouseAction() == df::MouseAction::CLICKED)
			{
				WM.moveObject(this, df::Vector(getPosition().getX(), getPosition().getY() - 1));
			}
		}
		return 1;
	}
	if (p_event->getType() == df::COLLISION_EVENT)
	{
		auto collisionEvent = dynamic_cast<const df::EventCollision *>(p_event);
		if (collisionEvent)
		{
			df::Vector newVel(getVelocity().getY(), 0);
			setVelocity(newVel);
		}
	}
	return 0;
}

void TestObject::step()
{
	LM.writeLog("TestObject::step(): Position incremented to: %f, %f", getPosition().getX(), getPosition().getY());
}

void TestObject::out()
{
	df::Vector newVel = getVelocity();
	if (newVel.getX() != 0)
	{
		newVel.setXY(0, newVel.getX() * -1);
		if (getPosition().getY() > 0)
		{
			WM.moveObject(this, df::Vector(79, getPosition().getY()));
			LM.writeLog("TestObject::out(): It's out the side.");
		}
	}
	else
	{
		newVel.setXY(newVel.getY(), 0);
		if (getPosition().getY() <= 0)
		{
			WM.moveObject(this, df::Vector(getPosition().getX(), getPosition().getY() + 1));
			LM.writeLog("TestObject::out(): It's out the top.");
		}
	}
	setVelocity(newVel);
	LM.writeLog("TestObject::out(): Direction reversed.");
}

void TestObject::draw()
{
	DM.drawString(getPosition(), "DEBUG_DISPLAY", df::Justification::LEFT_JUSTIFIED, df::Color::WHITE);
}

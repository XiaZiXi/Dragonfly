#include "LogManager.h"

#include "EventStep.h"

#include "TestObject.h"

TestObject::TestObject(float startX, float startY)
{
	df::Vector pos(startX, startY);
	setPosition(pos);
}

TestObject::~TestObject()
{
	LM.writeLog("TestObject::~TestObject(): Deleting TestObject at position: %f, %f", getPosition().getX(), getPosition().getY());
}

int TestObject::eventHandler(const df::Event *p_event)
{
	if (p_event->getType() == df::STEP_EVENT)
	{
		step();
		return 1;
	}
	return 0;
}

void TestObject::step()
{
	df::Vector currPos = getPosition();
	setPosition(df::Vector(currPos.getX() + 1, currPos.getY()));
	LM.writeLog("TestObject::step(): Position incremented to: %f, %f", getPosition().getX(), getPosition().getY());
}

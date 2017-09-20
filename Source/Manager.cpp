#include "WorldManager.h"

#include "ObjectListIterator.h"

#include "Manager.h"

void df::Manager::setType(std::string type)
{
	m_type = type;
}

df::Manager::Manager()
{
}

df::Manager::~Manager()
{
}

std::string df::Manager::getType() const
{
	return m_type;
}

int df::Manager::startUp()
{
	m_isStarted = true;
	return 0;
}

void df::Manager::shutDown()
{
	m_isStarted = false;
}

bool df::Manager::isStarted() const
{
	return m_isStarted;
}

int df::Manager::onEvent(const df::Event *p_event) const
{
	int count = 0;

	ObjectList allObjects = WM.getAllObjects();
	ObjectListIterator iter(&allObjects);
	for (iter.first(); !iter.isDone(); iter.next())
	{
		iter.currentObject()->eventHandler(p_event);
		count++;
	}

	return count;
}

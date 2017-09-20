#include "LogManager.h"

#include "WorldManager.h"

df::WorldManager::WorldManager() 
{
	setType("WorldManager");

	m_updates = ObjectList();
	m_deletions = ObjectList();
}

df::WorldManager & df::WorldManager::getInstance()
{
	static WorldManager worldManager;
	return worldManager;
}

int df::WorldManager::startUp()
{
	Manager::startUp();

	LM.writeLog("WorldManager::startUp(): Starting up the World Manager!");
	return 0;
}

void df::WorldManager::shutDown()
{
	LM.writeLog("WorldManager::shutDown(): Shutting down the World Manager.");

	// Delete all game objects.
	ObjectList oldList = m_updates;
	ObjectListIterator iter(&oldList);
	for (iter.first(); !iter.isDone(); iter.next())
	{
		delete iter.currentObject();
	}

	Manager::shutDown();
}

int df::WorldManager::insertObject(Object *p_obj)
{
	return m_updates.insert(p_obj);
}

int df::WorldManager::removeObject(Object *p_obj)
{
	bool status = m_updates.remove(p_obj);
	return status;
}

df::ObjectList df::WorldManager::getAllObjects() const
{
	LM.writeLog("WorldManager::getAllObjects(): Object count: %d", m_updates.getCount());
	return m_updates;
}

df::ObjectList df::WorldManager::objectsOfType(std::string type) const
{
	ObjectList objectsOfType;
	ObjectListIterator iter(&m_updates);
	for (iter.first(); !iter.isDone(); iter.next())
	{
		if (iter.currentObject()->getType() == type)
		{
			objectsOfType.insert(iter.currentObject());
		}
	}
	return objectsOfType;
}

void df::WorldManager::update()
{
	ObjectListIterator iter(&m_deletions);
	for (iter.first(); !iter.isDone(); iter.next())
	{
		delete iter.currentObject();
	}
	m_deletions.clear();
}

int df::WorldManager::markForDelete(Object *p_obj)
{
	ObjectListIterator iter(&m_deletions);
	while (!iter.isDone())
	{
		if (iter.currentObject() == p_obj) // Object already in list.
		{
			return 0;
		}
		iter.next();
	}

	// Object not in list, so add.
	return m_deletions.insert(p_obj);
}

void df::WorldManager::draw()
{
	ObjectListIterator iter(&m_updates);
	for (iter.first(); !iter.isDone(); iter.next())
	{
		Object *p_tempObj = iter.currentObject();
		p_tempObj->draw();
	}
}

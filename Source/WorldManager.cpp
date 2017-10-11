#include "LogManager.h"
#include "DisplayManager.h"

#include "Utility.h"
#include "EventCollision.h"
#include "EventOut.h"

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
	ObjectListIterator updateIter(&m_updates);
	for (updateIter.first(); !updateIter.isDone(); updateIter.next())
	{
		Object *p_object = updateIter.currentObject();
		Vector newPos = p_object->predictPosition();

		// If Object should change position, then move.
		if (newPos != p_object->getPosition())
		{
			moveObject(p_object, newPos);
		}
	}

	ObjectListIterator deleteIter(&m_deletions);
	for (deleteIter.first(); !deleteIter.isDone(); deleteIter.next())
	{
		delete deleteIter.currentObject();
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

		// Bounding box coordinates are relative to Object, so convert to world coordinates.
		Box tempBox = Utility::getWorldBox(p_tempObj);

		// Only draw if Object wouls be visible on window (intersects view).
		if (Utility::boxIntersectsBox(tempBox, m_view))
		{
			p_tempObj->draw();
		}
	}
}

df::ObjectList df::WorldManager::isCollision(Object *p_object, Vector where) const
{
	ObjectList collisionList = ObjectList();

	// Iterate through all objects.
	ObjectListIterator iter(&m_updates);

	for (iter.first(); !iter.isDone(); iter.next())
	{
		Object *p_tempObj = iter.currentObject();
		if (p_tempObj != p_object) // Do not consider self.
		{
			// Same location and both solid.
			Box objectBox = Utility::getWorldBox(p_object, where);
			Box tempObjBox = Utility::getWorldBox(p_tempObj);

			if (Utility::boxIntersectsBox(objectBox, tempObjBox)
				&& p_tempObj->isSolid())
			{
				collisionList.insert(p_tempObj);
			}
		}
	}

	return collisionList;
}

int df::WorldManager::moveObject(Object *p_object, Vector where)
{
	if (p_object->isSolid())
	{
		// Get collisions.
		ObjectList list = isCollision(p_object, where);

		if (!list.isEmpty())
		{
			bool doMove = true;

			// Iterate over list.
			ObjectListIterator iter(&list);
			for (iter.first(); !iter.isDone(); iter.next())
			{
				Object *p_tempObj = iter.currentObject();

				// Create collision event.
				EventCollision collision(p_object, p_tempObj, where);

				// Send to both objects.
				p_object->eventHandler(&collision);
				p_tempObj->eventHandler(&collision);

				// If both HARD, then cannot move.
				if (p_object->getSolidness() == HARD && p_tempObj->getSolidness() == HARD)
				{
					doMove = false;
				}
			}

			if (!doMove)
			{
				LM.writeLog("WorldManager::moveObject(): Did Not Move Object.");
				return -1;
			}
		}
	}
	Vector originalPos = p_object->getPosition();

	Box originalBox = Utility::getWorldBox(p_object);	// Original bounding box.
	p_object->setPosition(where);						// Move object.
	Box newBox = Utility::getWorldBox(p_object);		// New bounding box.

	// Check for out of bounds.
	// If it is already out of bounds, don't send Out Event.
	if (Utility::boxIntersectsBox(originalBox, m_boundary) &&
		!Utility::boxIntersectsBox(newBox, m_boundary))
	{
		// Generate out of bounds event and send to Object.
		EventOut out = EventOut();
		p_object->eventHandler(&out);
		LM.writeLog("WorldManager::moveObject(): Out Event sent.");
	}

	// If view is following this object, adjust view.
	if (m_p_viewFollowing == p_object)
	{
		setViewPosition(p_object->getPosition());
	}

	return 0;
}

void df::WorldManager::setBoundary(Box newBoundary)
{
	m_boundary = newBoundary;
}

df::Box df::WorldManager::getBoundary() const
{
	return m_boundary;
}

void df::WorldManager::setView(Box newView)
{
	m_view = newView;
}

df::Box df::WorldManager::getView() const
{
	return m_view;
}

void df::WorldManager::setViewPosition(Vector viewPos)
{
	// Make sure horizontal not out of world boundary.
	float x = viewPos.getX() - m_view.getWidth() / 2;
	if (x + m_view.getWidth() > m_boundary.getWidth())
	{
		x = m_boundary.getWidth() - m_view.getWidth();
	}
	if (x < 0)
	{
		x = 0;
	}

	// Make sure vertical not out of world boundary.
	float y = viewPos.getY() - m_view.getHeight() / 2;
	if (y + m_view.getHeight() > m_boundary.getHeight())
	{
		y = m_boundary.getHeight() - m_view.getHeight();
	}
	if (y < 0)
	{
		y = 0;
	}

	// Set view.
	Vector newCorner(x, y);
	m_view.setCorner(newCorner);
}

int df::WorldManager::setViewFollowing(Object *p_newViewFollowing)
{
	// Set to NULL to turn 'off' following.
	if (p_newViewFollowing == NULL)
	{
		m_p_viewFollowing = NULL;
		return 0;
	}

	// Iterate over all Objects. Make sure p_newViewFollowing is one of the Objects.
	ObjectListIterator iter(&m_updates);
	for (iter.first(); !iter.isDone(); iter.next())
	{
		if (iter.currentObject() == p_newViewFollowing)
		{
			m_p_viewFollowing = p_newViewFollowing;
			setViewPosition(m_p_viewFollowing->getPosition());
			return 0;
		}
	}

	// Object was never found. Don't change current view.
	return -1;
}

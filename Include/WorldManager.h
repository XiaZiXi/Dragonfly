#pragma once

#include "Manager.h"
#include "ObjectList.h"

namespace df {
#define WM df::WorldManager::getInstance()

class WorldManager : public Manager {
private:
	WorldManager();			// Private since a singleton.

	ObjectList m_updates;	// All Objects in world to update.
	ObjectList m_deletions;	// All Objects in world to delete.

public:
	WorldManager(WorldManager const&) = delete;		// Don't allow copy.
	void operator=(WorldManager const&) = delete;	// Don't allow assignment.

	// Get the singleton instance of the WorldManager.
	static WorldManager &getInstance();

	// Start up game world (initialize everthing to empty).
	int startUp();

	// Shut down game world (delete all game world Objects).
	void shutDown();

	// Insert Object into world. Return 0 if ok, else -1.
	int insertObject(Object *p_obj);

	// Remove Object from world. Return 0 if ok, else -1.
	int removeObject(Object *p_obj);

	// Return list of all Objects in world.
	ObjectList getAllObjects() const;

	// Return list of Objects in world matching type.
	ObjectList objectsOfType(std::string type) const;

	// Update world.
	// Delete Objects marked for deletion.
	void update();

	// Indicate Object is to be deleted at end of current game loop.
	// Return 0 if ok, else -1.
	int markForDelete(Object *p_obj);

	// Draw all objects.
	void draw();
};
}
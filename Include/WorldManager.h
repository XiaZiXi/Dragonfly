#pragma once

#include "Manager.h"
#include "ObjectList.h"

namespace df {
const int MAX_ALTITUDE = 4;

#define WM df::WorldManager::getInstance()

class WorldManager : public Manager {
private:
	WorldManager();				// Private since a singleton.

	ObjectList m_updates;		// All Objects in world to update.
	ObjectList m_deletions;		// All Objects in world to delete.

	Box m_boundary;				// World boundary.
	Box m_view;					// Player view of game world.

	Object *m_p_viewFollowing;	// Object view is following.

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

	// Return list of Objects collided with at poistion 'where'.
	// Collisions only with solid Objects.
	// Does not consider if p_object is solid or not.
	ObjectList isCollision(Object *p_object, Vector where) const;

	// Move Object.
	// If collision with solid, send collision events.
	// If no collision with solid, move ok else don't move Object.
	// If Object is Spectral, move ok.
	// Return - if move ok, else -1 if collision with solid.
	int moveObject(Object *p_object, Vector where);

	// Get/Set game world boundary.
	void setBoundary(Box newBoundary);
	Box getBoundary() const;

	// Get/Set player view of game world.
	void setView(Box newView);
	Box getView() const;

	// Set view to center window on position viewPos.
	// View edge will not go beyond world boundary.
	void setViewPosition(Vector viewPos);

	// Set view to center window on Object.
	// Set to NULL to stop following.
	// If p_newViewFollowing invalid return -1, else return 0.
	int setViewFollowing(Object *p_newViewFollowing);
};
}
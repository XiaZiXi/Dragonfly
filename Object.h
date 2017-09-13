#pragma once

#include <string>

#include "Vector.h"

namespace df {
class Object {
private:
	int m_id;			// Unique game engine defined identifier.
	std::string m_type;	// Game-programmer defined identification.
	Vector m_position;	// Position in game world.

public:
	// Construct Object. Set default parameters and add to game world (WorldManager).
	Object();

	// Destroy Object. Remove from game world (WorldManager).
	virtual ~Object();

	// Get/Set Object id.
	void setId(int newId);
	int getId() const;

	// Get/Set identifier of Object.
	void setType(std::string newType);
	std::string getType() const;

	// Get/Set position of Object.
	void setPosition(Vector newPos);
	Vector getPosition() const;
};
}
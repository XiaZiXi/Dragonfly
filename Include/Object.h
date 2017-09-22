#pragma once

#include <string>

#include "Event.h"
#include "Vector.h"
#include "Solidness.h"

namespace df {
static int uid = 0;

class Object {
private:
	int m_id;				// Unique game engine defined identifier.
	std::string m_type;		// Game-programmer defined identification.
	Vector m_position;		// Position in game world.
	Vector m_direction;		// Direction vector.
	float m_speed;			// Object speed in direction.
	Solidness m_solidness;	// Solidness of Object.

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

	// Handle event (default is to ignore everythin).
	// Return 0 if ignored, else 1 if handled.
	virtual int eventHandler(const Event *p_event);

	// Empty virtual draw method which is overridden in children with special draw methods.
	virtual void draw() {};

	// Get/Set speed of Object.
	void setSpeed(float newSpeed);
	float getSpeed() const;

	// Get/Set direction of Object.
	void setDirection(Vector newDirection);
	Vector getDirection() const;

	// Get/Set velocity of Object based on direction and speed.
	void setVelocity(Vector newVelocity);
	Vector getVelocity() const;

	// Predict Object position based on speed and direction.
	// Return predicted position.
	Vector predictPosition();

	// True if HARD or SOFT, else false.
	bool isSolid() const;

	// Set object solidness, with checks for consistency.
	// Return 0 if ok, else -1.
	int setSolidness(Solidness newSolid);

	// Get object solidness.
	Solidness getSolidness() const;
};
}
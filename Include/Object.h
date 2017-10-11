#pragma once

#include <string>

#include "Event.h"
#include "Vector.h"
#include "Solidness.h"
#include "Sprite.h"
#include "Box.h"

namespace df {
static int uid = 0;

class Object {
private:
	int m_id;					// Unique game engine defined identifier.
	std::string m_type;			// Game-programmer defined identification.
	Vector m_position;			// Position in game world.
	Vector m_direction;			// Direction vector.
	float m_speed;				// Object speed in direction.
	Solidness m_solidness;		// Solidness of Object.
	Box m_box;					// Box for sprite boundary and collisions.

	Sprite *m_p_sprite;			// Sprite associated with object.
	bool m_spriteCenter;		// True if sprite centered on object.
	int m_spriteIndex;			// Current index frame for sprite.
	int m_spriteSlowdown;		// Slowdown rate (1 = no slowdown, 0 = stop).
	int m_spriteSlowdownCount;	// Slowdown counter.

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

	// Get/Set Object's bounding box.
	void setBox(Box newBox);
	Box getBox() const;

	// Set Object Sprite to new one.
	// If setBox is true, set bounding box to size of Sprite.
	// Set sprite index to 0 (first frame).
	void setSprite(Sprite *p_newSprite, bool setBox = true);

	// Return pointer to Sprite associated with this Object.
	Sprite *getSprite() const;

	// Get/Set Sprite to be centered at Object position.
	void setCentered(bool centered = true);
	bool isCentered() const;

	// Get/Set index of current Sprite frame to be displayed.
	void setSpriteIndex(int newSpriteIndex);
	int getSpriteIndex() const;

	// Slows down sprite animations.
	// Sprite slowdown is in multiples of GameManager frame time.
	void setSpriteSlowdown(int newSpriteSlowdown);
	int getSpriteSlowdown() const;

	void setSpriteSlowdownCount(int newSpriteSlowdownCount);
	int getSpriteSlowdownCount() const;

	// Draw single sprite frame.
	// Drawing accounts for center and slowdown, and advances Sprite frame.
	virtual void draw();
};
}
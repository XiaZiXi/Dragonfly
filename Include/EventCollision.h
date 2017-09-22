#pragma once

#include <string>

#include "Object.h"
#include "Event.h"

namespace df {
const std::string COLLISION_EVENT = "df::collision";

class EventCollision : public Event {
private:
	Vector m_pos;			// Where collision occurred.
	Object *m_p_object1;	// Object moving, causing collision.
	Object *m_p_object2;	// Object being collided with.

public:
	// Create collision event at (0, 0) with o1 and o2 NULL.
	EventCollision();

	// Create collision event between o1 and o2 at position pos.
	// Object o1 'caused' collision by moving into object o2.
	EventCollision(Object *p_o1, Object *p_o2, Vector pos);

	// Get/Set object that caused collision.
	void setObject1(Object *p_newObject1);
	Object *getObject1() const;

	// Get/Set object that was collided with.
	void setObject2(Object *p_newObject2);
	Object *getObject2() const;

	// Get/Set position of collision.
	void setPosition(Vector newPos);
	Vector getPosition() const;
};
}
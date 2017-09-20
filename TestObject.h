#pragma once

#include "Event.h"
#include "Object.h"

class TestObject : public df::Object {
public:
	TestObject(float startX, float startY);
	~TestObject();

	// Overload Event Handler.
	virtual int eventHandler(const df::Event *p_event);

	// Handle Step Event.
	void step();
};
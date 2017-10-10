#pragma once

#include "Event.h"
#include "Object.h"

class TestVelocityObject : public df::Object {
public:
	TestVelocityObject();
	~TestVelocityObject();

	// Overload Event Handler.
	virtual int eventHandler(const df::Event *p_event);

	// Handle Out Event.
	void out();

	virtual void draw();
};
#pragma once

#include "Event.h"
#include "Object.h"

class TestBoundaryObject : public df::Object {
public:
	TestBoundaryObject();
	~TestBoundaryObject();

	// Overload Event Handler.
	virtual int eventHandler(const df::Event *p_event);

	virtual void draw();
};
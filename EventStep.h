#pragma once

#include <string>

#include "Event.h"

namespace df {
const std::string STEP_EVENT = "df::step";

class EventStep : public Event {
private:
	int m_stepCount; // Iteration number of game loop.

public:
	// Default constructor.
	EventStep();

	// Constructor with initial step count.
	EventStep(int initStepCount);

	// Get/Set step count.
	void setStepCount(int newStepCount);
	int getStepCount() const;
};
}
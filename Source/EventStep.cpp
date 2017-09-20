#include "EventStep.h"

df::EventStep::EventStep() : EventStep(0) {}

df::EventStep::EventStep(int initStepCount)
{
	Event::setType(STEP_EVENT);
	m_stepCount = initStepCount;
}

void df::EventStep::setStepCount(int newStepCount)
{
	m_stepCount = newStepCount;
}

int df::EventStep::getStepCount() const
{
	return m_stepCount;
}

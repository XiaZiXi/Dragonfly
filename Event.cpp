#include "Event.h"

df::Event::Event()
{
	m_eventType = UNDEFINED_EVENT;
}

df::Event::~Event()
{
}

void df::Event::setType(std::string newType)
{
	m_eventType = newType;
}

std::string df::Event::getType() const
{
	return m_eventType;
}

#pragma once

#include <string>

const std::string UNDEFINED_EVENT = "df::undefined";

namespace df {
class Event {
private:
	std::string m_eventType; // Holds event type.

public:
	// Create base event.
	Event();

	// Destructor.
	virtual ~Event();

	// Get/Set event type.
	void setType(std::string newType);
	std::string getType() const;
};
}
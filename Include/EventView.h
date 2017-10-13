#pragma once

#include "Event.h"

namespace df {
const std::string VIEW_EVENT = "df::view";

class EventView : public Event {
private:
	std::string m_tag;	// Tag to associate.
	int m_value;		// Value for view.
	bool m_delta;		// True if change in value, else replace value.

public:
	// Create view event with tag VIEW_EVENT, value 0, and delta false.
	EventView();

	// Create view event with tag, value, and delta as indicated.
	EventView(std::string tag, int value, bool delta);

	// Get/Set tag.
	void setTag(std::string newTag);
	std::string getTag() const;

	// Get/Set value.
	void setValue(int newValue);
	int getValue() const;

	// Get/Set delta.
	void setDelta(bool newDelta);
	bool getDelta() const;
};
}
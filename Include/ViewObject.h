#pragma once

#include <string>

#include "Object.h"
#include "Event.h"
#include "ViewObjectLocation.h"

namespace df {
class ViewObject : public Object {
private:
	std::string m_viewString;		// Label for value (ex. "Points").
	int m_value;					// Value displayed.
	bool m_drawValue;				// True if should draw value.
	bool m_border;					// True if border around display.
	Color m_color;					// Color for text (and border).
	ViewObjectLocation m_location;	// Location of ViewObject.

public:
	// Construct ViewObject.
	// Object settings: SPECTRAL, max alt.
	// ViewObject defaults: border, top_center, default color, drawValue.
	ViewObject();

	// Draw view string and value.
	virtual void draw();

	// Handle 'view' event if tag matches viewString (others ignored).
	// Return 0 if ignored, else 1 if handled.
	virtual int eventHandler(const Event *p_event);

	// Get/Set general location of ViewObject on screen.
	void setLocation(ViewObjectLocation newLocation);
	ViewObjectLocation getLocation() const;

	// Get/Set view value.
	void setValue(int newValue);
	int getValue() const;

	// Get/Set view border (true = display border).
	void setBorder(bool newBorder);
	bool getBorder() const;

	// Get/Set view color.
	void setColor(Color newColor);
	Color getColor() const;

	// Get/Set view display string.
	void setViewString(std::string newViewString);
	std::string getViewString() const;

	// Get/Set draw value with display string (true = draw value with display string).
	void setDrawValue(bool newDrawValue = true);
	bool getDrawValue() const;
};
}
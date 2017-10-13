#include "DisplayManager.h"

#include "Utility.h"
#include "EventView.h"

#include "ViewObject.h"

df::ViewObject::ViewObject()
{
	// Initialize Object attributes.
	setSolidness(SPECTRAL);
	setType("ViewObject");
	setAltitude(MAX_ALTITUDE);

	// Initialize ViewObject attributes.
	setValue(0);
	setDrawValue();
	setBorder(true);
	setLocation(TOP_CENTER);
	setColor(COLOR_DEFAULT);
	setCentered();
}

void df::ViewObject::draw()
{
	std::string tempStr;

	// Display m_viewString and value.
	if (m_border)
	{
		tempStr = " " + getViewString() + " " + Utility::toString(m_value) + " ";
	}
	else
	{
		tempStr = getViewString() + " " + Utility::toString(m_value);
	}

	// Draw centered at position.
	Vector pos = Utility::viewToWorld(getPosition());
	DM.drawString(pos, tempStr, CENTER_JUSTIFIED, getColor());

	if (m_border)
	{
		// Draw box around display.
	}
}

int df::ViewObject::eventHandler(const Event *p_event)
{
	// See if this is 'view' event.
	if (p_event->getType() == VIEW_EVENT)
	{
		const EventView *p_viewEvent = static_cast <const EventView *>(p_event);

		// See if this event is meant for this object.
		if (p_viewEvent->getTag() == getViewString())
		{
			if (p_viewEvent->getDelta())
			{
				setValue(getValue() + p_viewEvent->getValue()); // Change in value.
			}
			else
			{
				setValue(p_viewEvent->getValue()); // New value.
			}

			return 1; // Event was handled.
		}
	}

	// If here, event was not handled. Call parent eventHandler().
	return Object::eventHandler(p_event);
}

void df::ViewObject::setLocation(ViewObjectLocation newLocation)
{
	// Set new position based on location.
	Vector tempPos = ViewObjectLocationHelper::getScreenPosition(newLocation);

	// Check for invalid location.
	if (tempPos == Vector())
	{
		return;
	}

	if (!getBorder())
	{
		// Shift as needed based on border.
		tempPos.setY(tempPos.getY() + ViewObjectLocationHelper::getYDelta(newLocation));
	}

	// Set position of object to new position.
	setPosition(tempPos);

	// Set new location.
	m_location = newLocation;
}

df::ViewObjectLocation df::ViewObject::getLocation() const
{
	return m_location;
}

void df::ViewObject::setValue(int newValue)
{
	m_value = newValue;
}

int df::ViewObject::getValue() const
{
	return m_value;
}

void df::ViewObject::setBorder(bool newBorder)
{
	if (m_border != newBorder)
	{
		m_border = newBorder;
		
		// Reset location to account for border setting.
		setLocation(getLocation());
	}
}

bool df::ViewObject::getBorder() const
{
	return m_border;
}

void df::ViewObject::setColor(Color newColor)
{
	m_color = newColor;
}

df::Color df::ViewObject::getColor() const
{
	return m_color;
}

void df::ViewObject::setViewString(std::string newViewString)
{
	m_viewString = newViewString;
}

std::string df::ViewObject::getViewString() const
{
	return m_viewString;
}

void df::ViewObject::setDrawValue(bool newDrawValue)
{
	m_drawValue = newDrawValue;
}

bool df::ViewObject::getDrawValue() const
{
	return m_drawValue;
}

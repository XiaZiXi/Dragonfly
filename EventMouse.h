#pragma once

#include "Vector.h"
#include "Button.h"
#include "MouseAction.h"
#include "Event.h"

namespace df {
	const std::string MOUSE_EVENT = "df::mouse";

	class EventMouse : public Event {
	private:
		MouseAction m_mouseAction;		// Mouse action.
		Mouse::Button m_mouseButton;	// Mouse button.
		Vector m_mousePos;				// Mouse (x, y) coordinates.
	public:
		// Default constructor.
		EventMouse();

		// Get/Set mouse event's action
		void setMouseAction(MouseAction newMouseAction);
		MouseAction getMouseAction() const;

		// Get/Set mouse event's button
		void setMouseButton(Mouse::Button newButton);
		Mouse::Button getMouseButton() const;

		// Get/Set mouse event's position
		void setMousePosition(Vector newPos);
		Vector getMousePosition() const;

	};
}
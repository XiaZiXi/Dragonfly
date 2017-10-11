#pragma once
#include "Vector.h"

namespace df {
class Box {
private:
	Vector m_corner;	// Upper left corner of box.
	float m_width;	// Horizontal dimension.
	float m_height;	// Vertical dimension.

public:
	// Create box with (0, 0) for the corner, and 0 for width and height.
	Box();

	// Create box with an upper-left corner, width and height sizes.
	Box(Vector initCorner, float initWidth, float initHeight);

	// Get/Set upper left corner of box.
	void setCorner(Vector newCorner);
	Vector getCorner() const;

	// Get/Set Width.
	void setWidth(float newWidth);
	float getWidth() const;

	// Get/Set Height.
	void setHeight(float newHeight);
	float getHeight() const;
};
}
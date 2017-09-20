#pragma once

namespace df {
class Vector {
private:
	float m_x;	// Horizontal component.
	float m_y;	// Vertical component.

public:
	// Create Vector with (x, y).
	Vector(float initX, float initY);

	// Default 2d (x, y) is (0, 0).
	Vector();

	// Get/Set horizontal component.
	void setX(float newX);
	float getX() const;

	// Get/Set vertical component.
	void setY(float newX);
	float getY() const;

	// Set horizontal & vertical components.
	void setXY(float newX, float newY);

	// Return magnitude of vector.
	float getMagnitude() const;

	// Normalize vector.
	void normalize();

	// Scale vector.
	void scale(float s);

	// Add two Vectors, return new Vector.
	Vector operator+(const Vector &other) const;
};
}
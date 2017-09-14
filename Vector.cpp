#include <math.h>

#include "LogManager.h"

#include "Vector.h"

df::Vector::Vector(float initX, float initY)
{
	m_x = initX;
	m_y = initY;
}

df::Vector::Vector()
{
	m_x = 0;
	m_y = 0;
}

void df::Vector::setX(float newX)
{
	m_x = newX;
}

float df::Vector::getX() const
{
	return m_x;
}

void df::Vector::setY(float newX)
{
	m_y = newX;
}

float df::Vector::getY() const
{
	return m_y;
}

void df::Vector::setXY(float newX, float newY)
{
	m_x = newX;
	m_y = newY;
}

float df::Vector::getMagnitude() const
{
	float mag = sqrt((m_x * m_x) + (m_y * m_y));
	return mag;
}

void df::Vector::normalize()
{
	float length = getMagnitude();
	if (length > 0)
	{
		m_x = m_x / length;
		m_y = m_y / length;
	}
}

void df::Vector::scale(float s)
{
	m_x = m_x * s;
	m_y = m_y * s;
}

df::Vector df::Vector::operator+(const Vector & other) const
{
	Vector v;
	v.m_x = m_x + other.m_x;	// Add x components.
	v.m_y = m_y + other.m_y;	// Add y components.
	return v;
}

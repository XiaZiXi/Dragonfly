#include "Box.h"

df::Box::Box()
{
	m_corner = Vector();
	m_width = 0;
	m_height = 0;
}

df::Box::Box(Vector initCorner, float initWidth, float initHeight)
{
	m_corner = initCorner;
	m_width = initWidth;
	m_height = initHeight;
}

void df::Box::setCorner(Vector newCorner)
{
	m_corner = newCorner;
}

df::Vector df::Box::getCorner() const
{
	return m_corner;
}

void df::Box::setWidth(float newWidth)
{
	m_width = newWidth;
}

float df::Box::getWidth() const
{
	return m_width;
}

void df::Box::setHeight(float newHeight)
{
	m_height = newHeight;
}

float df::Box::getHeight() const
{
	return m_height;
}

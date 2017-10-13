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

void df::Box::setHorizontal(float newWidth)
{
	m_width = newWidth;
}

float df::Box::getHorizontal() const
{
	return m_width;
}

void df::Box::setVertical(float newHeight)
{
	m_height = newHeight;
}

float df::Box::getVertical() const
{
	return m_height;
}

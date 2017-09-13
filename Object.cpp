#include "Object.h"

df::Object::Object()
{
	m_position = Vector();
}

df::Object::~Object()
{
}

void df::Object::setId(int newId)
{
	m_id = newId;
}

int df::Object::getId() const
{
	return m_id;
}

void df::Object::setType(std::string newType)
{
	m_type = newType;
}

std::string df::Object::getType() const
{
	return m_type;
}

void df::Object::setPosition(Vector newPos)
{
	m_position = newPos;
}

df::Vector df::Object::getPosition() const
{
	return m_position;
}

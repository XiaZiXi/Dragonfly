#include "EventCollision.h"

df::EventCollision::EventCollision()
{
	setType(COLLISION_EVENT);
	m_pos = Vector(0, 0);
	m_p_object1 = NULL;
	m_p_object2 = NULL;
}

df::EventCollision::EventCollision(Object *p_o1, Object *p_o2, Vector pos)
{
	setType(COLLISION_EVENT);
	m_pos = pos;
	m_p_object1 = p_o1;
	m_p_object2 = p_o2;
}

void df::EventCollision::setObject1(Object *p_newObject1)
{
	m_p_object1 = p_newObject1;
}

df::Object *df::EventCollision::getObject1() const
{
	return m_p_object1;
}

void df::EventCollision::setObject2(Object *p_newObject2)
{
	m_p_object2 = p_newObject2;
}

df::Object *df::EventCollision::getObject2() const
{
	return m_p_object2;
}

void df::EventCollision::setPosition(Vector newPos)
{
	m_pos = newPos;
}

df::Vector df::EventCollision::getPosition() const
{
	return m_pos;
}

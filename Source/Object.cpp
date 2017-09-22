#include "LogManager.h"
#include "WorldManager.h"

#include "Object.h"

df::Object::Object()
{
	m_position = Vector(0, 0);
	// Sets the unique id.
	setId(uid);
	uid++;

	// Add self to game world.
	WM.insertObject(this);
}

df::Object::~Object()
{
	// Remove self from game world.
	WM.removeObject(this);
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

int df::Object::eventHandler(const Event * p_event)
{
	return 0;
}

void df::Object::setSpeed(float newSpeed)
{
	m_speed = newSpeed;
}

float df::Object::getSpeed() const
{
	return m_speed;
}

void df::Object::setDirection(Vector newDirection)
{
	m_direction = newDirection;
}

df::Vector df::Object::getDirection() const
{
	return m_direction;
}

void df::Object::setVelocity(Vector newVelocity)
{
	m_speed = newVelocity.getMagnitude();
	newVelocity.normalize();
	m_direction = newVelocity;
}

df::Vector df::Object::getVelocity() const
{
	Vector velocity = m_direction;
	velocity.scale(m_speed);
	return velocity;
}

df::Vector df::Object::predictPosition()
{
	Vector newPos = m_position + getVelocity();
	return newPos;
}

bool df::Object::isSolid() const
{
	return (m_solidness == Solidness::HARD || m_solidness == Solidness::SOFT);
}

int df::Object::setSolidness(Solidness newSolid)
{
	m_solidness = newSolid;
	return 0;
}

df::Solidness df::Object::getSolidness() const
{
	return m_solidness;
}

#include "LogManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"

#include "Object.h"

df::Object::Object()
{
	setSolidness(Solidness::HARD); // By default objects are HARD.
	m_position = Vector(0, 0);
	// Sets the unique id.
	setId(uid);
	uid++;

	m_box = Box();

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

void df::Object::setBox(Box newBox)
{
	m_box = newBox;
}

df::Box df::Object::getBox() const
{
	return m_box;
}

void df::Object::setSprite(Sprite *p_newSprite, bool setBox)
{
	m_p_sprite = p_newSprite;
}

df::Sprite *df::Object::getSprite() const
{
	return m_p_sprite;
}

void df::Object::setCentered(bool centered)
{
	m_spriteCenter = centered;
}

bool df::Object::isCentered() const
{
	return m_spriteCenter;
}

void df::Object::setSpriteIndex(int newSpriteIndex)
{
	m_spriteIndex = newSpriteIndex;
}

int df::Object::getSpriteIndex() const
{
	return m_spriteIndex;
}

void df::Object::setSpriteSlowdown(int newSpriteSlowdown)
{
	m_spriteSlowdown = newSpriteSlowdown;
}

int df::Object::getSpriteSlowdown() const
{
	return m_spriteSlowdown;
}

void df::Object::setSpriteSlowdownCount(int newSpriteSlowdownCount)
{
	m_spriteSlowdownCount = newSpriteSlowdownCount;
}

int df::Object::getSpriteSlowdownCount() const
{
	return m_spriteSlowdownCount;
}

void df::Object::draw()
{
	// If sprite not defined, don't continue further.
	if (m_p_sprite == NULL)
	{
		return;
	}

	int index = getSpriteIndex();

	// Ask graphics manager to draw current frame.
	DM.drawFrame(m_position, m_p_sprite->getFrame(index), m_spriteCenter, m_p_sprite->getColor());

	// If slowdown is 0, then animation is frozen.
	if (getSpriteSlowdown() == 0)
	{
		return;
	}

	// Increment counter.
	int count = getSpriteSlowdownCount();
	count++;

	// Advance sprite index if appropriate.
	if (count >= getSpriteSlowdown())
	{
		count = 0; // Reset counter.
		index++; // Advance frame.

		// If at last frame, loop to beginning.
		if (index >= m_p_sprite->getFrameCount())
		{
			index = 0;
		}
	}

	// Set counter and index for next draw().
	setSpriteSlowdownCount(count);
	setSpriteIndex(index);

}

#include "Manager.h"

void df::Manager::setType(std::string type)
{
	m_type = type;
}

df::Manager::Manager()
{
}

df::Manager::~Manager()
{
}

std::string df::Manager::getType() const
{
	return m_type;
}

int df::Manager::startUp()
{
	m_isStarted = true;
	return 0;
}

void df::Manager::shutDown()
{
	m_isStarted = false;
}

bool df::Manager::isStarted() const
{
	return m_isStarted;
}

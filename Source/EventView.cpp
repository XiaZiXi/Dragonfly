#include "EventView.h"

df::EventView::EventView()
{
	setType(VIEW_EVENT);
	m_tag = VIEW_EVENT;
	m_value = 0;
	m_delta = false;
}

df::EventView::EventView(std::string tag, int value, bool delta)
{
	setType(VIEW_EVENT);
	m_tag = tag;
	m_value = value;
	m_delta = delta;
}

void df::EventView::setTag(std::string newTag)
{
	m_tag = newTag;
}

std::string df::EventView::getTag() const
{
	return m_tag;
}

void df::EventView::setValue(int newValue)
{
	m_value = newValue;
}

int df::EventView::getValue() const
{
	return m_value;
}

void df::EventView::setDelta(bool newDelta)
{
	m_delta = newDelta;
}

bool df::EventView::getDelta() const
{
	return m_delta;
}

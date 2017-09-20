#include "ObjectListIterator.h"

df::ObjectListIterator::ObjectListIterator() {}

df::ObjectListIterator::ObjectListIterator(const ObjectList *p_list)
{
	m_p_list = p_list;
	first();
}

void df::ObjectListIterator::first()
{
	m_index = 0;
}

void df::ObjectListIterator::next()
{
	if (m_index < m_p_list->m_count)
	{
		m_index++;
	}
}

bool df::ObjectListIterator::isDone() const
{
	return (m_index == m_p_list->m_count);
}

df::Object *df::ObjectListIterator::currentObject() const
{
	return m_p_list->m_p_obj[m_index];
}

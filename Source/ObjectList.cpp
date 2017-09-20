#include "LogManager.h"

#include "ObjectList.h"

df::ObjectList::ObjectList()
{
	m_count = 0;
}

int df::ObjectList::insert(Object *p_obj)
{
	if (m_count == MAX_OBJECTS)
	{
		return -1;
	}

	m_p_obj[m_count] = p_obj;
	m_count++;
	return 0;
}

int df::ObjectList::remove(Object *p_obj)
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_p_obj[i] == p_obj)
		{
			for (int j = i; j < m_count - 1; j++)
			{
				m_p_obj[j] = m_p_obj[j + 1];
			}
			m_count--;
			return 0; // Found.
		}
	}
	LM.writeLog("ObjectList::remove(): Could not find Object.");
	return -1; // Not found.
}

void df::ObjectList::clear()
{
	m_count = 0;
}

int df::ObjectList::getCount() const
{
	return m_count;
}

bool df::ObjectList::isEmpty() const
{
	return (m_count == 0);
}

bool df::ObjectList::isFull() const
{
	return (m_count == MAX_OBJECTS);
}

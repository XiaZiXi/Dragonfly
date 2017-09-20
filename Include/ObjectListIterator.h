#pragma once

#include "Object.h"
#include "ObjectList.h"

namespace df {
// Forward Declarations.
class ObjectList;

class ObjectListIterator {
private:
	ObjectListIterator();	// Must be given list when created.

	int m_index;				// Index into list.
	const ObjectList *m_p_list;	// List iterating over.

public:
	// Create iterator over indicated list.
	ObjectListIterator(const ObjectList *p_list);

	// Set iterator to first item in list.
	void first();

	// Set iterator to next item in list.
	void next();

	// Return true if at end of list.
	bool isDone() const;

	// Return pointer to current Object, NULL if done/empty/
	Object *currentObject() const;
};
}
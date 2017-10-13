#pragma once
#include <stdlib.h>

#include "Vector.h"
#include "Box.h"
#include "Object.h"

namespace df {
class Utility {
public:
	// Return true if two positions intersect, else false.
	static bool positionsIntersect(Vector p1, Vector p2);

	// Return true if boxes intersect, else false.
	static bool boxIntersectsBox(Box a, Box b);

	// Returns the collision box converted to world coordinates.
	static Box getWorldBox(const Object *p_object);

	// Returns the collision box at position where converted to world coordinates.
	static Box getWorldBox(const Object *p_object, Vector where);

	// Convert world position to view position.
	static Vector worldToView(Vector worldPos);

	// Convert view position to world position.
	static Vector viewToWorld(Vector viewPos);

	// Convert int to a string, returning string.
	static std::string toString(int i);
};
}
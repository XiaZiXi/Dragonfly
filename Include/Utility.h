#pragma once
#include <stdlib.h>

#include "Vector.h"

namespace df {
class Utility {
public:
	// Return true if two positions intersect, else false.
	static bool positionsIntersect(Vector p1, Vector p2);
};
}
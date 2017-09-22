#include "Utility.h"

bool df::Utility::positionsIntersect(Vector p1, Vector p2)
{
	return (abs((int)(p1.getX() - p2.getX())) <= 1 &&
		abs((int)(p1.getY() - p2.getY())) <= 1);
}
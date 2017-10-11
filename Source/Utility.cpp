#include "WorldManager.h"
#include "Utility.h"

bool df::Utility::positionsIntersect(Vector p1, Vector p2)
{
	return (abs((int)(p1.getX() - p2.getX())) <= 1 &&
		abs((int)(p1.getY() - p2.getY())) <= 1);
}

bool df::Utility::boxIntersectsBox(Box a, Box b)
{
	float aX1 = a.getCorner().getX();
	float aY1 = a.getCorner().getY();
	float aX2 = aX1 + a.getWidth();
	float aY2 = aY1 + a.getHeight();

	float bX1 = b.getCorner().getX();
	float bY1 = b.getCorner().getY();
	float bX2 = bX1 + b.getWidth();
	float bY2 = bY1 + b.getHeight();

	// Test horizontal overlap (xOverlap).
	bool xOverlap = (bX1 <= aX1 && aX1 <= bX2) || (aX1 <= bX1 && bX1 <= aX2);

	// Test vertical overlap (yOverlap).
	bool yOverlap = (bY1 <= aY1 && aY1 <= bY2) || (aY1 <= bY1 && bY1 <= aY2);

	if (xOverlap && yOverlap)
	{
		return true; // Boxes do intersect.
	}

	return false; // Boxes do not intersect.
}

df::Box df::Utility::getWorldBox(const Object *p_object)
{
	return getWorldBox(p_object, p_object->getPosition());
}

df::Box df::Utility::getWorldBox(const Object *p_object, Vector where)
{
	Box tempBox = p_object->getBox();
	Vector corner = tempBox.getCorner();
	corner.setX(corner.getX() + where.getX());
	corner.setY(corner.getY() + where.getY());
	tempBox.setCorner(corner);

	return tempBox;
}

df::Vector df::Utility::worldToView(Vector worldPos)
{
	Vector viewOrigin = WM.getView().getCorner();
	float viewX = viewOrigin.getX();
	float viewY = viewOrigin.getY();
	Vector viewPos(worldPos.getX() - viewX, worldPos.getY() - viewY);
	return viewPos;
}

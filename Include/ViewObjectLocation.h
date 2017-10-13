#pragma once

#include "Vector.h"
#include "WorldManager.h"

namespace df {

// General location of ViewObject on screen.
enum ViewObjectLocation {
	UNDEFINED = -1,
	TOP_LEFT,
	TOP_CENTER,
	TOP_RIGHT,
	CENTER_LEFT,
	CENTER_CENTER,
	CENTER_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT
};

class ViewObjectLocationHelper {
public:
	static Vector getScreenPosition(ViewObjectLocation location)
	{
		Vector screenPos = Vector();

		// Return a position based on location.
		switch (location)
		{
		case TOP_LEFT:
			screenPos.setXY(WM.getView().getHorizontal() * 1/6, 1);
			break;
		case TOP_CENTER:
			screenPos.setXY(WM.getView().getHorizontal() * 3/6, 1);
			break;
		case TOP_RIGHT:
			screenPos.setXY(WM.getView().getHorizontal() * 5/6, 1);
			break;
		case CENTER_LEFT:
			screenPos.setXY(WM.getView().getHorizontal() * 1/6, WM.getView().getVertical() / 2);
			break;
		case CENTER_CENTER:
			screenPos.setXY(WM.getView().getHorizontal() * 3/6, WM.getView().getVertical() / 2);
			break;
		case CENTER_RIGHT:
			screenPos.setXY(WM.getView().getHorizontal() * 5/6, WM.getView().getVertical() / 2);
			break;
		case BOTTOM_LEFT:
			screenPos.setXY(WM.getView().getHorizontal() * 1/6, WM.getView().getVertical() - 1);
			break;
		case BOTTOM_CENTER:
			screenPos.setXY(WM.getView().getHorizontal() * 3/6, WM.getView().getVertical() - 1);
			break;
		case BOTTOM_RIGHT:
			screenPos.setXY(WM.getView().getHorizontal() * 5/6, WM.getView().getVertical() - 1);
			break;
		}

		return screenPos;
	};

	static int getYDelta(ViewObjectLocation location)
	{
		// Return a y delta based on location.
		switch (location)
		{
		case TOP_LEFT:
			return -1;
		case TOP_CENTER:
			return -1;
		case TOP_RIGHT:
			return -1;
		case BOTTOM_LEFT:
			return 1;
		case BOTTOM_CENTER:
			return 1;
		case BOTTOM_RIGHT:
			return 1;
		}

		return 0;
	};
};
}
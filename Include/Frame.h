#pragma once
#include <string>

namespace df {
class Frame {
private:
	int m_width;				// Width of frame.
	int m_height;				// Height of frame.
	std::string m_frameStr;	// All frame characters stored as a string.

public:
	// Create empty frame.
	Frame();

	// Create frame of indicated width and height with string.
	Frame(int newWidth, int newHeight, std::string frameStr);

	// Get/Set width of frame.
	void setWidth(int newWidth);
	int getWidth() const;

	// Get/Set height of frame.
	void setHeight(int newHeight);
	int getHeight() const;

	// Get/Set frame characters (stored as string).
	void setString(std::string newFrameStr);
	std::string getString() const;
};
}
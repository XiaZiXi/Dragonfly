#pragma once
#include <string>

#include "Frame.h"
#include "Color.h"

namespace df {
class Sprite {
private:
	int m_width;			// Sprite width.
	int m_height;			// Sprite height.
	int m_maxFrameCount;	// Max number of frames sprite can have.
	int m_frameCount;		// Actual number frames sprite has.
	Color m_color;			// Optional color for entire sprite.
	Frame *m_frame;			// Array of frames.
	std::string m_label;	// Text label to identify sprite.
	Sprite();				// Sprite always has one arg.

public:
	// Destroy sprite, deleting any allocated frames.
	~Sprite();

	// Create sprite with indicated maximum number of frames.
	Sprite(int maxFrames);

	// Get/Set width of sprite.
	void setWidth(int newWidth);
	int getWidth() const;

	// Get/Set height of sprite.
	void setHeight(int newHeight);
	int getHeight() const;

	// Get/Set sprite color.
	void setColor(Color newColor);
	Color getColor() const;

	// Get total cound of frames in sprite.
	int getFrameCount() const;

	// Add frame to sprite.
	// Return -1 if frame array full, else 0.
	int addFrame(Frame newFrame);

	// Get next sprite frame indicated by number.
	// Return empty frame if out of range [0, frameCount].
	Frame getFrame(int frameNumber) const;

	// Get/Set label associated with sprite.
	void setLabel(std::string newLabel);
	std::string getLabel() const;
};
}
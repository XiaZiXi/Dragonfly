#include "Sprite.h"

df::Sprite::~Sprite()
{
}

df::Sprite::Sprite(int maxFrames)
{
	m_frameCount = 0;
	m_width = 0;
	m_height = 0;
	m_frame = new Frame[maxFrames];
	m_maxFrameCount = maxFrames;
	m_color = COLOR_DEFAULT;
}

void df::Sprite::setWidth(int newWidth)
{
	m_width = newWidth;
}

int df::Sprite::getWidth() const
{
	return m_width;
}

void df::Sprite::setHeight(int newHeight)
{
	m_height = newHeight;
}

int df::Sprite::getHeight() const
{
	return m_height;
}

void df::Sprite::setColor(Color newColor)
{
	m_color = newColor;
}

df::Color df::Sprite::getColor() const
{
	return m_color;
}

int df::Sprite::getFrameCount() const
{
	return m_frameCount;
}

int df::Sprite::addFrame(Frame newFrame)
{
	if (m_frameCount == m_maxFrameCount)
	{
		return 1; // Sprite is full.
	}
	else
	{
		m_frame[m_frameCount] = newFrame;
		m_frameCount++;
	}
	return 0;
}

df::Frame df::Sprite::getFrame(int frameNumber) const
{
	if ((frameNumber < 0) || (frameNumber >= m_frameCount))
	{
		return Frame();
	}

	return m_frame[frameNumber];
}

void df::Sprite::setLabel(std::string newLabel)
{
	m_label = newLabel;
}

std::string df::Sprite::getLabel() const
{
	return m_label;
}

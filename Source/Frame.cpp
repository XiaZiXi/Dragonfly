#include "Frame.h"

df::Frame::Frame()
{
}

df::Frame::Frame(int newWidth, int newHeight, std::string frameStr)
{
	m_width = newWidth;
	m_height = newHeight;
	m_frameStr = frameStr;
}

void df::Frame::setWidth(int newWidth)
{
	m_width = newWidth;
}

int df::Frame::getWidth() const
{
	return m_width;
}

void df::Frame::setHeight(int newHeight)
{
	m_height = newHeight;
}

int df::Frame::getHeight() const
{
	return m_height;
}

void df::Frame::setString(std::string newFrameStr)
{
	m_frameStr = newFrameStr;
}

std::string df::Frame::getString() const
{
	return m_frameStr;
}

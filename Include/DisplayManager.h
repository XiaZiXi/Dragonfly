#pragma once

#include <SFML/Graphics.hpp>

#include "Color.h"
#include "Vector.h"
#include "Justification.h"
#include "Frame.h"
#include "Manager.h"

namespace df {
// Defaults for SFML window.
const int WINDOW_HORIZONTAL_PIXELS_DEFAULT = 1024;
const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar;
const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
const std::string FONT_FILE_DEFAULT = "df-font.ttf";

#define DM df::DisplayManager::getInstance()

class DisplayManager : public Manager {
private:
	DisplayManager();				// Private since a singleton.

	sf::Font m_font;				// Font used for ASCII graphics.
	sf::RenderWindow *m_p_window;	// Pointer to SFML window.
	int m_windowHorizontalPixels;	// Horizontal pixels in window.
	int m_windowVerticalPixels;		// Vertical pixels in window.
	int m_windowHorizontalChars;	// Horizontal ASCII spaces in window.
	int m_windowVerticalChars;		// Vertical ASCII spaces in window.

public:
	DisplayManager(DisplayManager const &copy) = delete;	// Don't allow copy.
	void operator=(DisplayManager const &assign) = delete;	// Don't allow assignment

	// Get the singleton instance of the DisplayManager.
	static DisplayManager &getInstance();

	// Start up all DisplayManager services.
	int startUp();

	// Shut down all DisplayManager services.
	void shutDown();

	// Draw character at window location (x, y) with color.
	// Return 0 if ok, else -1.
	int drawCh(Vector world_pos, char ch, Color color) const;

	// Draw string at window location (x, y) with default color,
	// Justified left, center, or right.
	// Return 0 if ok, else -1.
	int drawString(Vector pos, std::string str, Justification just, Color color) const;

	// Draw single sprite frame at window location (x, y) with color.
	// If centered true then center frame at (x, y).
	// Return 0 if ok, else -1.
	int drawFrame(Vector worldPos, Frame frame, bool centered, Color color) const;

	// Compute character width/height, based on window size and font.
	float charHeight() const;
	float charWidth() const;

	// Convert ASCII spaces (x, y) to window pixels (x, y).
	Vector spacesToPixels(Vector spaces) const;

	// Convert window pixels (x, y) to ASCII spaces (x, y).
	Vector pixelsToSpaces(Vector pixels) const;

	// Return window's horizontal maximum (in characters).
	int getHorizontal() const;

	// Return window's vertical maximum (in characters).
	int getVertical() const;

	// Return window's horizontal maximum (in pixels).
	int getHorizontalPixels() const;

	// Return window's vertical maximum (in pixels).
	int getVerticalPixels() const;

	// Render current window buffer.
	// Return 0 if ok, else -1.
	int swapBuffers();

	// Return pointer to SFML drawing window.
	sf::RenderWindow *getWindow() const;
};
}
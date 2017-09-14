#pragma once

#include <SFML/Graphics.hpp>

#include "Color.h"
#include "Vector.h"
#include "Manager.h"

namespace df {
// Defaults for SFML window.
const int WINDOW_HORIZAONTAL_PIXELS_DEFAULT = 1024;
const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar;
const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
const std::string FONT_FILE_DEFAULT = "df-font.ttf";

class DisplayManager : public Manager {
private:
	DisplayManager();						// Private since a singleton.
	DisplayManager(DisplayManager const &);	// Don't allow copy.
	void operator=(DisplayManager const &);	// Don't allow assignment

	sf::Font m_font;				// Font used for ASCII graphics.
	sf::RenderWindow *m_p_window;	// Pointer to SFML window.
	int m_window_horizontal_pixels;	// Horizontal pixels in window.
	int m_window_vertical_pixels;	// Vertical pixels in window.
	int m_window_horizontal_chars;	// Horizontal ASCII spaces in window.
	int m_window_vertical_chars;	// Vertical ASCII spaces in window.

public:
	// Get the singleton instance of the DisplayManager.
	static DisplayManager &getInstance();

	// Start up all DisplayManager services.
	int startUp();

	// Shut down all DisplayManager services.
	void shutDown();

	// Draw character at window location (x, y) with color.
	// Return 0 if ok, else -1.
	int drawCh(Vector world_pos, char ch, Color color) const;

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
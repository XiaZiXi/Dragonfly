#include "LogManager.h"

#include "DisplayManager.h"

df::DisplayManager::DisplayManager()
{
	m_p_window = NULL;
}

df::DisplayManager &df::DisplayManager::getInstance()
{
	static DisplayManager displayManager;
	return displayManager;
}

int df::DisplayManager::startUp()
{
	if (m_p_window != NULL)
	{
		return 0;
	}

	// Create window to draw on.
	m_p_window = new sf::RenderWindow(sf::VideoMode(WINDOW_HORIZONTAL_PIXELS_DEFAULT, WINDOW_VERTICAL_PIXELS_DEFAULT), WINDOW_TITLE_DEFAULT);
	if (!m_p_window)
	{
		LM.writeLog("Error! Unable to allocate RenderWindow.");
		return -1;
	}

	// Turn off mouse cursor for window.
	m_p_window->setMouseCursorVisible(false);

	// Synchronize refresh rate with monitor.
	m_p_window->setVerticalSyncEnabled(true);

	// Load font.
	if (m_font.loadFromFile(FONT_FILE_DEFAULT) == false)
	{
		LM.writeLog("Error! Unable to load font: %s.", FONT_FILE_DEFAULT);
		return -1;
	}

	Manager::startUp();
	return 0;
}

void df::DisplayManager::shutDown()
{
	Manager::shutDown();
}

int df::DisplayManager::drawCh(Vector world_pos, char ch, Color color) const
{
	// Make sure window is allocated.
	if (m_p_window == NULL)
	{
		return -1;
	}

	// Convert spaces (x, y) to pixels (x, y).
	Vector pixelPos = spacesToPixels(world_pos);

	// Draw background rectangle since text is "see through" in SFML.
	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	rectangle.setPosition(
		pixelPos.getX() - charWidth() / 10,
		pixelPos.getY() + charHeight() / 5);
	m_p_window->draw(rectangle);

	// Create character text to draw.
	static sf::Text text("", m_font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold); // Make it bold since it looks better.

	// Scale to right size.
	if (charWidth() < charHeight())
	{
		text.setCharacterSize(charWidth() * 2);
	}
	else
	{
		text.setCharacterSize(charHeight() * 2);
	}

	// Set SFML color based on Dragonfly color.
	text.setFillColor(ColorHelper::convertToSFML(color));

	// Set position in window (in pixels).
	text.setPosition(pixelPos.getX(), pixelPos.getY());

	// Draw character.
	m_p_window->draw(text);

	return 0;
}

int df::DisplayManager::drawString(Vector pos, std::string str, Justification just, Color color) const
{
	// Get starting position.
	Vector startingPos = pos;
	switch (just)
	{
	case Justification::CENTER_JUSTIFIED:
		startingPos.setX(pos.getX() - str.size() / 2);
		break;
	case Justification::RIGHT_JUSTIFIED:
		startingPos.setX(pos.getX() - str.size());
		break;
	case Justification::LEFT_JUSTIFIED:
		break;
	default:
		break;
	}

	// Draw string character by character.
	for (int i = 0; i < str.size(); i++)
	{
		Vector tempPos(startingPos.getX() + i, startingPos.getY());
		drawCh(tempPos, str[i], color);
	}

	return 0;
}

float df::DisplayManager::charHeight() const
{
	return getVerticalPixels() / getVertical();
}

float df::DisplayManager::charWidth() const
{
	return getHorizontalPixels() / getHorizontal();
}

df::Vector df::DisplayManager::spacesToPixels(Vector spaces) const
{
	return Vector(spaces.getX() * charWidth(), spaces.getY() * charHeight());
}

df::Vector df::DisplayManager::pixelsToSpaces(Vector pixels) const
{
	return Vector(pixels.getX() / charWidth(), pixels.getY() / charHeight());
}

int df::DisplayManager::getHorizontal() const
{
	return m_windowHorizontalChars;
}

int df::DisplayManager::getVertical() const
{
	return m_windowVerticalChars;
}

int df::DisplayManager::getHorizontalPixels() const
{
	return m_windowHorizontalPixels;
}

int df::DisplayManager::getVerticalPixels() const
{
	return m_windowVerticalPixels;
}

int df::DisplayManager::swapBuffers()
{
	// Make sure window is allocated.
	if (m_p_window == NULL)
	{
		return -1;
	}

	// Display current window.
	m_p_window->display();

	// Clear window to get ready for next draw.
	m_p_window->clear();

	return 0;
}

sf::RenderWindow *df::DisplayManager::getWindow() const
{
	return m_p_window;
}
